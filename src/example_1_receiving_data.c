/************************************************************************************ 
* Driver use example 1: Receiving data 
* 
* ps: At first, set nRF24L01 SPI and control PINS 
*     Then, include driver file. 
*     Now, that´s all right 
*/ 
void RF24_driver_use_example_RXdata() {    //Example of using this driver 
   int RXbuffer1[32], RXbuffer2[32], RXbuffer3[32]; 
   int RXbuffer4[32], RXbuffer5[32]; 
   int RXdatasize, RXpipe; 
   //int TXbuffer[40], TXdatasize;        //not necessary 
   //int stat=0,fstat=0,retrys,lost,ret;  // 
   //int i=false; 
    
   RF24_initPorts(); 
   RF24_default_config(); 
    
   //RF24_check_config();    //check configuration  

   RF24_RX_SET();       //Receiver on 
   while(true) { 
      
      while ( RF24_RX_getbuffer(&RXpipe, &RXdatasize, RXbuffer1)!=true );    //Wait till receive data(1 to 32 bytes) into buffer(from default_config address of pipe0) 
      while ( RF24_RX_getbuffer(&RXpipe, &RXdatasize, RXbuffer2)!=true );    //Wait till receive data(1 to 32 bytes) into buffer(from default_config address of pipe0) 
      while ( RF24_RX_getbuffer(&RXpipe, &RXdatasize, RXbuffer3)!=true );    //Wait till receive data(1 to 32 bytes) into buffer(from default_config address of pipe0) 
      while ( RF24_RX_getbuffer(&RXpipe, &RXdatasize, RXbuffer4)!=true );    //Wait till receive data(1 to 32 bytes) into buffer(from default_config address of pipe0) 
      while ( RF24_RX_getbuffer(&RXpipe, &RXdatasize, RXbuffer5)!=true );    //Wait till receive data(1 to 32 bytes) into buffer(from default_config address of pipe0) 
      
      
      /*while (!i) { 
         i=RF24_RX_getbuffer(&RXpipe, &RXdatasize, RXbuffer1);    //Wait till receive data(1 to 32 bytes) into buffer(from default_config address of pipe0) 
         if (!i) buzzer_off(); 
         else { buzzer_on(); delay_ms(10); buzzer_off(); } 
      } 
      i=false;*/ 
    
      //RF24_STATUS_clr_IRQs(IRQ_ALL);      //Allows clearing all IRQs at the same time 
      
      //fstat=RF24_FIFO_STATUS(); 
      //stat=RF24_get_status(); 
      //buzzer_on(); delay_ms(1); buzzer_off(); //Beepa Buzzer 
      delay_cycles(1); 
   } 
    

}