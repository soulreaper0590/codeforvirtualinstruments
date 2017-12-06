After uploading and putting the bluetooth module in AT mode, type this 
#FOR MASTER:

AT   //output should be okay for all commands
AT+UART
AT+ROLE=1;
AT+CMODE=0;
AT+BIND=(PUT THE ADDRESS OF SLAVE AND PUT COMMAS INSTEAD OF SEMI-COLONS)


#FOR SLAVE

AT
AT+UART
AT+ROLE=0;
AT+ADDR