set talk off
do while .t.
use \xsk\&y\fox1-99
store password to ax1
store "        " to ax2
set colo to bg+/7+
*@11,39 clear to 20,60
store 21 to col1
store 8 to row1
@11,39 say ""
do he-hhll

@12,41 say " �� �޸����� ��"FONT"����",12
@14,41 say "�� �� ��: "+"********"FONT"����",12
store 8 to col1
store 0 to row1
@16,50 say ""
do he-llhh
@16,41 say "�� �� ��:"FONT"����",12
@16,50 get ax2 FONT"����",12 SIZE 0.85,8
*@16,30 say "����Ա��" get na FONT"����",12
STORE 0 TO aba 
@18,41 get aba FUNCTION "*TH YES;NO;EXIT" SIZE 1.5,5.8 ;
COLOR RGB(255,255,255,,,)FONT"����",10
read
if ax2="        "
store ax1 to ax2
endif
do case
case aba=1
repl password with ax2
exit
case aba=3
exit
endcase
enddo
set colo to 7/bg+
@0,0 clear
return

