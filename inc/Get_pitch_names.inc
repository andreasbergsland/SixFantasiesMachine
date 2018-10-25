
;**************************************************************************
;
;		SIX FANTASIES MACHINE, version 0.50beta
;
;**************************************************************************
;A sound making tool based on Six Fantasies on a Poem by Thomas 
;Campion by Paul Lansky. The tool uses LPC analysis/resynthesis 
;and filtering to emulate the range of vocal transformations that 
;can be heard in Lansky's piece.

;Copyright (C) 2009  Andreas Bergsland
;
;This program is free software: you can redistribute it and/or modify
;it under the terms of the GNU General Public License as published by
;the Free Software Foundation, either version 3 of the License, or
;(at your option) any later version.
;
;This program is distributed in the hope that it will be useful,
;but WITHOUT ANY WARRANTY; without even the implied warranty of
;MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
;GNU General Public License for more details.
;
;You should have received a copy of the GNU General Public License
;along with this program.  If not, see <http://www.gnu.org/licenses/>.

;***************************************************************************

;inc/Get_pitch_names.inc

;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
;			Get pitch names
;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


#define	SLIDERINPUT(G)
#
; init trigger values
ktrig$G.01	init		0
ktrig$G.02	init		0
ktrig$G.03	init		0
ktrig$G.04	init		0
ktrig$G.05	init		0
ktrig$G.06	init		0

; detect if the values of the pitch sliders change
ktrig$G.01	changed		gkPchVal$G.01
ktrig$G.02	changed		gkPchVal$G.02
ktrig$G.03	changed		gkPchVal$G.03
ktrig$G.04	changed		gkPchVal$G.04
ktrig$G.05	changed		gkPchVal$G.05
ktrig$G.06	changed		gkPchVal$G.06

; convert via oct-format...
koct$G.01	=		octcps(gkPchVal$G.01)
koct$G.02	=		octcps(gkPchVal$G.02)
koct$G.03	=		octcps(gkPchVal$G.03)
koct$G.04	=		octcps(gkPchVal$G.04)
koct$G.05	=		octcps(gkPchVal$G.05)
koct$G.06	=		octcps(gkPchVal$G.06)
;...to pch format
kpch$G.01	=		pchoct(koct$G.01)
kpch$G.02	=		pchoct(koct$G.02)
kpch$G.03	=		pchoct(koct$G.03)
kpch$G.04	=		pchoct(koct$G.04)
kpch$G.05	=		pchoct(koct$G.05)
kpch$G.06	=		pchoct(koct$G.06)

; Get a pitch value in the pch-format without the octave integer
kPchNoOct$G.01	=		kpch$G.01 - int(kpch$G.01)
kPchNoOct$G.02	=		kpch$G.02 - int(kpch$G.02)
kPchNoOct$G.03	=		kpch$G.03 - int(kpch$G.03)
kPchNoOct$G.04	=		kpch$G.04 - int(kpch$G.04)
kPchNoOct$G.05	=		kpch$G.05 - int(kpch$G.05)
kPchNoOct$G.06	=		kpch$G.06 - int(kpch$G.06)

;Convert to integers so thate 0.0=C, 1.0=C sharp, 2.0=D, etc.
kPchRaw$G.01	=		kPchNoOct$G.01 * 100	
kPchRaw$G.02	=		kPchNoOct$G.02 * 100	;
kPchRaw$G.03	=		kPchNoOct$G.03 * 100
kPchRaw$G.04	=		kPchNoOct$G.04 * 100
kPchRaw$G.05	=		kPchNoOct$G.05 * 100
kPchRaw$G.06	=		kPchNoOct$G.06 * 100

; Round off pitch values
kPchRound$G.01	=		int( kPchRaw$G.01 +.5)
kPchRound$G.02	=		int( kPchRaw$G.02 +.5)
kPchRound$G.03	=		int( kPchRaw$G.03 +.5)
kPchRound$G.04	=		int( kPchRaw$G.04 +.5)
kPchRound$G.05	=		int( kPchRaw$G.05 +.5)
kPchRound$G.06	=		int( kPchRaw$G.06 +.5)

; Set octaves to be equivalent
kPchValInt$G.01	=		(kPchRound$G.01 ==12? 0 : kPchRound$G.01)
kPchValInt$G.02	=		(kPchRound$G.02 ==12? 0 : kPchRound$G.02)
kPchValInt$G.03	=		(kPchRound$G.03 ==12? 0 : kPchRound$G.03)
kPchValInt$G.04	=		(kPchRound$G.04 ==12? 0 : kPchRound$G.04)
kPchValInt$G.05	=		(kPchRound$G.05 ==12? 0 : kPchRound$G.05)
kPchValInt$G.06	=		(kPchRound$G.06 ==12? 0 : kPchRound$G.06)

;printk	.2, kPchValInt101

; Get deviation between raw pitch value and rounded value
kdev$G.01	=		kPchRaw$G.01 - kPchRound$G.01
kdev$G.02	=		kPchRaw$G.02 - kPchRound$G.02
kdev$G.03	=		kPchRaw$G.03 - kPchRound$G.03
kdev$G.04	=		kPchRaw$G.04 - kPchRound$G.04
kdev$G.05	=		kPchRaw$G.05 - kPchRound$G.05
kdev$G.06	=		kPchRaw$G.06 - kPchRound$G.06


;printk	1, kdev101

; Alternative conditional statements
imaxdev		=	0.1

if		(kdev$G.01 < -imaxdev)	then
ktune$G.01	=		80099
endif

if		(kdev$G.02 < -imaxdev)	then
ktune$G.02	=		80099
endif

if		(kdev$G.03 < -imaxdev)	then
ktune$G.03	=		80099
endif

if		(kdev$G.04 < -imaxdev)	then
ktune$G.04	=		80099
endif

if		(kdev$G.05 < -imaxdev)	then
ktune$G.05	=		80099
endif

if		(kdev$G.06 < -imaxdev)	then
ktune$G.06	=		80099
endif

if		(kdev$G.01 >  imaxdev)	then
ktune$G.01	=		80101
endif

if		(kdev$G.02 >  imaxdev)	then
ktune$G.02	=		80101
endif

if		(kdev$G.03 >  imaxdev)	then
ktune$G.03	=		80101
endif

if		(kdev$G.04 >  imaxdev)	then
ktune$G.04	=		80101
endif

if		(kdev$G.05 >  imaxdev)	then
ktune$G.05	=		80101
endif

if		(kdev$G.06 >  imaxdev)	then
ktune$G.06	=		80101
endif

if		(kdev$G.01 > -imaxdev && kdev$G.01 < imaxdev)	then
ktune$G.01	=		88888
endif

if		(kdev$G.02 > -imaxdev && kdev$G.02 < imaxdev)	then
ktune$G.02	=		88888
endif

if		(kdev$G.03 > -imaxdev && kdev$G.03 < imaxdev)	then
ktune$G.03	=		88888
endif

if		(kdev$G.04 > -imaxdev && kdev$G.04 < imaxdev)	then
ktune$G.04	=		88888
endif

if		(kdev$G.05 > -imaxdev && kdev$G.05 < imaxdev)	then
ktune$G.05	=		88888
endif

if		(kdev$G.06 > -imaxdev && kdev$G.06 < imaxdev)	then
ktune$G.06	=		88888
endif


contin$G:

kPitch$G.01	=		kPchValInt$G.01 + 80000
kPitch$G.02	=		kPchValInt$G.02 + 80000
kPitch$G.03	=		kPchValInt$G.03 + 80000
kPitch$G.04	=		kPchValInt$G.04 + 80000
kPitch$G.05	=		kPchValInt$G.05 + 80000
kPitch$G.06	=		kPchValInt$G.06 + 80000

imintime	=	500 / kr
imaxnum		=	8
insnum		=	41
;						       p2 p3   p4		p5	p6	       p7
schedkwhen	ktrig$G.01 , imintime, imaxnum, insnum, 0, .0, kPitch$G.01 , ktune$G.01 , gihPchName$G.01, $G
schedkwhen	ktrig$G.02 , imintime, imaxnum, insnum, 0, .0, kPitch$G.02 , ktune$G.02 , gihPchName$G.02, $G
schedkwhen	ktrig$G.03 , imintime, imaxnum, insnum, 0, .0, kPitch$G.03 , ktune$G.03 , gihPchName$G.03, $G
schedkwhen	ktrig$G.04 , imintime, imaxnum, insnum, 0, .0, kPitch$G.04 , ktune$G.04 , gihPchName$G.04, $G
schedkwhen	ktrig$G.05 , imintime, imaxnum, insnum, 0, .0, kPitch$G.05 , ktune$G.05 , gihPchName$G.05, $G
schedkwhen	ktrig$G.06 , imintime, imaxnum, insnum, 0, .0, kPitch$G.06 , ktune$G.06 , gihPchName$G.06, $G

ktrig$G.01	=	0
ktrig$G.02	=	0
ktrig$G.03	=	0
ktrig$G.04	=	0
ktrig$G.05	=	0
ktrig$G.06	=	0
#
