/* ========================================
 *
 * Description: Full audio AM transmitter
 * Author:      Joao Nuno Carvalho
 * Date:        2014.04.23
 *
 * ========================================
*/
#include <project.h>

int main()
{
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    Clock_1_carrier_Start();
    PWM_1_Start();
    IDAC_1_Start();
    
    /* Init and start sequencing SAR ADC */
    ADC_SAR_Seq_1_Start();
    ADC_SAR_Seq_1_StartConvert();
    
    OpAmp_Power_Amplifier_Start();
    
    /* CyGlobalIntEnable; */ /* Uncomment this line to enable global interrupts. */
    
    const uint32 channel_number = 0;  // ADC Channel 0.
    uint16 audio_value          = 0;
    float float_audio_value     = 0.0;
    float float_audio_value_amp = 0.0;
    const float upper_value  = 4096;
    const float medium_value = 2048; // 128 (8bits[255]), 512(10bits[1024]), 2048(12 bits[4096])
    const float upper_region_start_value = upper_value - (medium_value / 3.8);
    const float lower_region_start_value = 0 + (medium_value / 3.8);
    const float ampli_factor_main_region = 1.71;  //1.7; // 1.75; //1.7 //1.8; //1.5; //2.0;
    const float ampli_factor_extreme_region = 1.0; // 1.75; //1.7 //1.8; //1.5; //2.0;
    for(;;)
    {
        /* Place your application code here. */
        
        // Read ADC 12bits Analog to digital conversion value, the value is
        // double buffered so there is no risk of getting intermediate values.
        // It's continually running in free mode.
        audio_value = ADC_SAR_Seq_1_GetResult16(channel_number);
           
        // Digital amplification of the audio input signal.
        float_audio_value = audio_value;
        // Main region.
        if (   (float_audio_value > medium_value) 
            && (float_audio_value < upper_region_start_value))
            float_audio_value_amp = medium_value + 
                               ((float_audio_value - medium_value) * ampli_factor_main_region); 
        if (    (float_audio_value < medium_value)
            && (float_audio_value > lower_region_start_value))
            float_audio_value_amp = medium_value - 
                               ((medium_value - float_audio_value) * ampli_factor_main_region);
       /*
        // Extremes region.
        // Less amplification for the pick values, so it doesn't saturate.
        if (float_audio_value > upper_region_start_value)           
            float_audio_value_amp = medium_value + 
                               ((float_audio_value - medium_value) * ampli_factor_extreme_region); 
        if (float_audio_value < lower_region_start_value)
            float_audio_value_amp = medium_value - 
                               ((medium_value - float_audio_value) * ampli_factor_extreme_region);                                   
       */
                            
        // Converts from float32 to uint16. The range of this float numbers are always positive 
        audio_value = (uint16)(float_audio_value_amp / 8); // Has to map 0-4095 range to 0-255 range.
        
        IDAC_1_SetValue(audio_value);
        CyDelayUs(20); // 10us // 20us microseconds  [20KHz -> 40Ksamples gives 25us]
    }
}

/* [] END OF FILE */
