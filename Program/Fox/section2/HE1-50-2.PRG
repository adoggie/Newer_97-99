set talk off
do mm
yx=str((((val(y)*100+val(m))*100)+val(d)),6)
sele 1
use &gg inde &ggt1     &&������Ƭ��
sele 2
use &gg-d              &&��̬��Ƭ��
sele 3
use &gg-2              &&���ϵ���
sele 4
use &gg-h
store ���ձ����� to ax1
if val(yx)<=val(ax1)
return
endif
do while .T.
set colo to gr+/b
clear
@ 6,24 say '���������������Щ�������'
@ 7,24 say '����������: ��      ��'
@ 8,24 say '���������������ة�������'
xh1="      "
@ 7,40 get xh1 pict 'XXXXXX'
read
if xh1="     "
exit
endif
sele 1
use &gg inde &ggt1   &&������Ƭ��
seek trim(ltri(xh1))
if eof()
@14,24 say 'û�д˱��,������'
mx=0
do while mx<1000
mx=mx+1
enddo
loop
endif
do while .T.
sele 1
store spac(6) to tt1     &&���
store t2 to tt2          &&�ͺ�*
store t3 to tt3          &&ƽ����
store t3 to tt4          &&���ϵ���=ƽ����
store yx to tt5          &&����
store 0.00 to tt6        &&��������
store 0.00 to tt7        &&��������
store 0.00 to tt8        &&ʵ���ܼ�
store spac(6) to tt9     &&�ϵ���
store spac(4) to tt10    &&���
store spac(22) to tt11   &&���ϵ�λ
store t12 to tt12        &&�������
store t13 to tt13        &&�����
do ls-t
set colo to w+/g
@ 1,36 say xh1        &&���
@ 2,36 say tt2        &&�ͺ�
@ 4,36 get tt5        &&����
@ 6,36 get tt9        &&�ϵ���
@ 8,36 get tt10       &&���
@10,36 get tt11       &&���Ե�λ
@12,36 get tt6  pict "9999999.999"     &&����
@14,36 say tt3  pict "9999999.9"       &&�ƻ�����
@14,60 say tt4  pict "9999999.99"      &&ʵ�ʵ���
@17,36 say tt8  pict "9999999.99"      &&ʵ���ܼ�
@19,36 say tt12 pict "999999999.999"   &&ԭ�����
@21,36 say tt3  pict "9999999.9"       &&ԭ�ƻ���
@23,36 say tt13 pict "999999999.99"    &&ԭ�����
read
store val(str(tt6*tt3,10,2)) to tt8    &&�����ܼ�
store tt12+tt6 to tt12                 &&���Ӻ�����
store val(str(tt3*tt12,12,2)) to tt13  &&�仯������
set colo to r+/bg+
@14,36 say tt8 pict "9999999.99"       &&�����ܼ�
@19,60 say tt12 pict "9999999.999"     &&���Ӻ�����
@21,60 say tt3 pict "9999999.9"        &&�ּƻ���
@23,60 say tt13 pict "999999999.99"    &&�ֿ����
ss=" "
if tt8=0
set colo to r+/b+
@12,12 say "û������ !!!"
loop
endif
set colo to w+/g+
@22,0 clear to 24,20
@23,2 say '��ȷ��? (Y/N/0)' get ss
read
do case
case ss="0"
exit
case ss="n"
loop
case ss<>'n'
sele 1
repl t12 with tt12,t13 with tt13
sele 2
appe blan
repl t1 with xh1,t2 with tt2,t3 with tt3,t4 with tt4,;
t5 with tt5,t6 with t6,t7 with 0,t8 with tt8,t9 with tt9,;
t10 with tt10,t11 with tt11,t12 with tt12,t13 with tt13
sele 3
appe blan
repl t1 with xh1,t2 with tt2,t3 with tt3,t4 with tt4,;
t5 with tt5,t6 with tt6,t8 with tt8,t9 with tt9,;
t10 with tt10,t11 with tt11,t12 with tt12,t13 with tt13
sele 4
use &gg-h
repl ������ܶ� with ������ܶ�+tt8,;
�����ܶ� with �����ܶ�+tt8
exit
endcase
enddo
if ss="0"
exit
endif
set colo to g+/gr+
@22,0 clear to 24,20
ss=" "
@23,2 say '������? (Y/N)  ' get ss
read
if ss="n".or.ss="N"
exit
endif
enddo
close data
return

