set talk off
do while .t.
use fox1-99
store name to na
store password to ax1,qq1
store "        " to ax2
store " " to ax3
set colo to bg+/b+
@2,0 clear to 24,79
set colo to /n
@12,26 clear to 19,55
set colo to bg+/g+,bg+/n+
@11,24 clear to 18,53
@12,30 say "  �� �޸����� ��"
@14,30 say "�� �� �� "+qq1
@15,30 say "�� �� ��" get ax2
@16,30 say "����Ա��" get na
read
@17,30 say "��ȷ��? (Y/N/0)" get ax3
read
do case
case ax3="y".and.ax2<>"        "
repl password with ax2,name with na
exit
case ax3=" "
repl password with ax1,name with na
exit
case ax3="0"
exit
endcase
enddo
set colo to 7/7
@1,0 clear to 25,80
return

