set talk off
@row(),col()-col1 say ""
 =FORMA(ROW()-.2,COL()-.3,ROW()+1.1,COL()+col1+.2)
FUNCTION FORMA &&
PARAMETER RO1,CO1,RO2,CO2
@ RO1,CO1 TO RO1,CO2 PEN 1,8 STYLE "1" COLOR RGB(0,0,0,0,0,0)
@ RO1,CO2 TO RO2,CO2 PEN 1,8 STYLE "1" COLOR RGB(255,255,255,255,255,255)
@ RO2,CO1 TO RO2,CO2+.2 PEN 1,8 STYLE "1" COLOR RGB(255,255,255,255,255,255)  
@ RO1,CO1 TO RO2,CO1 PEN 1,8 STYLE "1" COLOR RGB(0,0,0,0,0,0)
return
