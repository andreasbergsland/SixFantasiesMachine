
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

;Set_factory_presents_instrument.inc


; Instrument for setting parameters to factory presets

instr	99
ifn	=	abs(p58)
ivoice	=	p56*100
ifile	=	p5-1000+100

; This routine enables import of Text-grid files from Praat, where the segments of the file from the recording matches
; the file from Lansky's original in terms of number of segments, and their contents. (Same phonemes is IMPORTANT!!! )
; It is also required that each segment in the text-grid files in Praat are specified with a start and an end boundary.
; Function table refers to Praat short text-grid files. The table opcode reads only number values from these files 
; and starts indexing from 0, thus indx=5 gives 6th numerical value in file. The files are specified as function tables in score.

iexport	=	ifile + 5000
iphfun	=	ifile + 9000				; Function table # for data from recording is 9 voice# ifile#
itrgfun	=	ifile + 80000 + ivoice*10		; Function table # for data from trg (Lanksy) is 8 voice# ifile#

iphend		table	1, iphfun			; Reads value for end of last segment in text-grid file from recording
itrgstart	table	0, itrgfun			; Reads value for start of first segment in text-grid file from Lansky's original
itrgend		table   1, itrgfun			; Reads value for end of last segment

iph1		table	8, iphfun			; iph# values reads consecutive time values from text-grid file from recording		
iph2		table	9, iphfun			; Since maximum number of segments needed were 15, 16 values are defined.
iph3		table	11, iphfun
iph4		table	13, iphfun
iph5		table	15, iphfun
iph6		table	17, iphfun
iph7		table	19, iphfun
iph8		table	21, iphfun
iph9		table	23, iphfun
iph10		table	25, iphfun
iph11		table	27, iphfun
iph12		table	29, iphfun
iph13		table	31, iphfun
iph14		table	33, iphfun
iph15		table	35, iphfun
iph16		table	37, iphfun

		
;iph2		=	iph2 - idel			; second and third values are adjusted for the "negative" delay. The first value is not adjusted
;iph3		=	iph3 - idel			; to prevent negative values, which will be refused by lpread
iph4		=	(iph4 ==iphend || iph4 ==0?  iph3 : iph4 )	; If value equals end value or zero, then set to last value. 
iph5		=	(iph5 ==iphend || iph5 ==0?  iph4 : iph5)	; This routine makes all values up to the last appear in an increasing order,
iph6		=	(iph6 ==iphend || iph6 ==0?  iph5: iph6)	; and values after the last boundary set to zero.
iph7		=	(iph7 ==iphend || iph7 ==0?  iph6 : iph7)
iph8		=	(iph8 ==iphend || iph8 ==0?  iph7: iph8)
iph9		=	(iph9 ==iphend || iph9 ==0?  iph8: iph9)
iph10		=	(iph10==iphend || iph10 ==0? iph9 : iph10)
iph11		=	(iph11==iphend || iph11 ==0? iph10: iph11)
iph12		=	(iph12==iphend || iph12 ==0? iph11: iph12)
iph13		=	(iph13==iphend || iph13 ==0? iph12: iph13)
iph14		=	(iph14==iphend || iph14 ==0? iph13: iph14)
iph15		=	(iph15==iphend || iph15 ==0? iph14: iph15)
iph16		=	(iph16==iphend || iph16 ==0? iph15: iph16)

iphdur1		=	iph2-iph1
iphdur2		=	iph3-iph2
iphdur3		=	iph4-iph3
iphdur4		=	iph5-iph4
iphdur5		=	iph6-iph5
iphdur6		=	iph7-iph6
iphdur7		=	iph8-iph7
iphdur8		=	iph9-iph8
iphdur9		=	iph10-iph9
iphdur10	=	iph11-iph10
iphdur11	=	iph12-iph11
iphdur12	=	iph13-iph12
iphdur13	=	iph14-iph13
iphdur14	=	iph15-iph14
iphdur15	=	iph16-iph15

iphdur1to3	=	iphdur2 + iphdur1


itrg1		table	8, itrgfun			; iph# values reads consecutive time values from text-grid file from original	
itrg2		table	9, itrgfun			; Since maximum number of segments needed were 15, 16 values are defined.
itrg3		table	11, itrgfun
itrg4		table	13, itrgfun
itrg5		table	15, itrgfun
itrg6		table	17, itrgfun
itrg7		table	19, itrgfun
itrg8		table	21, itrgfun
itrg9		table	23, itrgfun
itrg10		table	25, itrgfun
itrg11		table	27, itrgfun
itrg12		table	29, itrgfun
itrg13		table	31, itrgfun
itrg14		table	33, itrgfun
itrg15		table	35, itrgfun
itrg16		table   37, itrgfun


; Calculating durations for segments in target to be used by timepoint linseg for lpread
idr1		=	itrg2 - itrg1
idr2		=	itrg3 - itrg2
idr3		=	itrg4 - itrg3
idr4		=	itrg5 - itrg4
idr5		=	itrg6 - itrg5
idr6		=	itrg7 - itrg6
idr7		=	itrg8 - itrg7
idr8		=	itrg9 - itrg8
idr9		=	itrg10 - itrg9
idr10		=	itrg11- itrg10
idr11		=	itrg12- itrg11
idr12		=	itrg13- itrg12
idr13		=	itrg14 - itrg13
idr14		=	itrg15 - itrg14
idr15		=	itrg16 - itrg15

idr1to3		=	idr2 + idr1

; Calculating stretch factors for all segments
istr1		=	idr1 / iphdur1
istr2		=	idr2 / iphdur2
istr3		=	idr3 / iphdur3
istr4		=	idr4 / iphdur4
istr5		=	idr5 / iphdur5
istr6		=	idr6 / iphdur6
istr7		=	idr7 / iphdur7
istr8		=	idr8 / iphdur8
istr9		=	idr9 / iphdur9
istr10		=	idr10 / iphdur10
istr11		=	idr11 / iphdur11
istr12		=	idr12 / iphdur12
istr13		=	idr13 / iphdur13
istr14		=	idr14 / iphdur14
istr15		=	idr15 / iphdur15

istr1to3		=	idr1to3/iphdur1to3

; write source and target time points, plus duration values - calculate strech values from this - to tables
; then write tables to text files
;ihandle=222
;ihandle fiopen "BS_p-fields.txt", 0
;fouti	ihandle, 0, 0, iph1, iph3, iph4, iph5, iph6, iph7, iph8, iph9, iph10, iph11, iph12, iph13, iph15, iph15, iph16,\
; 0, istr1to3, istr3, istr4, istr5, istr6, istr7, istr8, istr9, istr10, istr11, istr12, istr13, istr14, istr15

	tablew 	p53, 	ivoice + 1, ifn 	; On/off
	tablew	p4, 	ivoice + 2, ifn 	; Volume
	tablew	p57, 	ivoice + 3, ifn 	; Chorus
	tablew	(1-p39),ivoice + 4, ifn		; RevMix
	tablew	p9, 	ivoice + 5, ifn 	; Pan
	tablew	p58,    ivoice + 51,ifn		; Noise level

; Use these lines from reading from text-grid files
if	ifn<0 igoto TextGrid

	tablew	p10, 	ivoice + 11, ifn	; FTP1
	tablew	p11, 	ivoice + 12, ifn	; FTP2
	tablew	p12, 	ivoice + 13, ifn	; FTP3
	tablew	p13, 	ivoice + 14, ifn	; FTP4
	tablew	p14, 	ivoice + 15, ifn	; FTP5
	tablew	p15, 	ivoice + 16, ifn	; FTP6
	tablew	p54, 	ivoice + 17, ifn	; FTP7

	tablew	p16,	ivoice + 21, ifn 	; Stretch1
	tablew	p17, 	ivoice + 22, ifn 	; Stretch2	
	tablew	p18, 	ivoice + 23, ifn 	; Stretch3	
	tablew	p19, 	ivoice + 24, ifn 	; Stretch4
	tablew	p20, 	ivoice + 25, ifn 	; Stretch5
	tablew	p55, 	ivoice + 26, ifn 	; Stretch6
igoto	Contin

TextGrid:
	tablew	iph1, 	ivoice + 11, ifn	; FTP1
	tablew	iph3, 	ivoice + 12, ifn	; FTP2
	tablew	iph4, 	ivoice + 13, ifn	; FTP3
	tablew	iph5, 	ivoice + 14, ifn	; FTP4
	tablew	iph6, 	ivoice + 15, ifn	; FTP5
	tablew	iph7, 	ivoice + 16, ifn	; FTP6
	tablew	iph8, 	ivoice + 17, ifn	; FTP7

	tablew	istr1to3,ivoice + 21, ifn 	; Stretch1
	tablew	istr3, 	ivoice + 22, ifn 	; Stretch2	
	tablew	istr4, 	ivoice + 23, ifn 	; Stretch3	
	tablew	istr5, 	ivoice + 24, ifn 	; Stretch4
	tablew	istr6, 	ivoice + 25, ifn 	; Stretch5
	tablew	istr7, 	ivoice + 26, ifn 	; Stretch6

Contin:

ipch0	=	(p21>20? p21: cpspch(p21))
ipch1	=	(p22>20? p22: cpspch(p22))
ipch2	=	(p23>20? p23: cpspch(p23))
ipch3	=	(p24>20? p24: cpspch(p24))
ipch4	=	(p25>20? p25: cpspch(p25))
ipch5	=	(p26>20? p26: cpspch(p26))

	tablew	ipch0,	ivoice + 31, ifn	; Pitch1
	tablew	ipch1,	ivoice + 32, ifn	; Pitch2
	tablew	ipch2,	ivoice + 33, ifn	; Pitch3
	tablew	ipch3,	ivoice + 34, ifn	; Pitch4
	tablew	ipch4,	ivoice + 35, ifn	; Pitch5
	tablew	ipch5,	ivoice + 36, ifn	; Pitch6

	tablew	p2,	ivoice + 41, ifn 	; Delay
	tablew	p7,	ivoice + 42, ifn 	; Range
	tablew	p38,	ivoice + 43, ifn 	; Transpose
	tablew	p6,	ivoice + 44, ifn 	; Noise/pitch
	tablew	p8,	ivoice + 45, ifn 	; Pitch from sliders/file 
	tablew 	.02, 	ivoice + 46, ifn	; Portamento
	tablew	p40, 	ivoice + 47, ifn	; FrqShift

	tablew	p5, 	ivoice + 50, ifn	; Phrase number
	
	
;ftsave "D:\Csound\Campion_machine_presets.txt",  1, ifn

endin