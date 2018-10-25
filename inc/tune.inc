
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

;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
;			Tune
;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

;"tune.inc"

#define	TUNE(U)
#
; Get values from pitch sliders
iHz$U.01		=	i(gkPchVal$U.01)
iHz$U.02		=	i(gkPchVal$U.02)
iHz$U.03		=	i(gkPchVal$U.03)
iHz$U.04		=	i(gkPchVal$U.04)
iHz$U.05		=	i(gkPchVal$U.05)
iHz$U.06		=	i(gkPchVal$U.06)

; convert via oct-format...
ioct$U.01	=	octcps(iHz$U.01)
ioct$U.02	=	octcps(iHz$U.02)
ioct$U.03	=	octcps(iHz$U.03)
ioct$U.04	=	octcps(iHz$U.04)
ioct$U.05	=	octcps(iHz$U.05)
ioct$U.06	=	octcps(iHz$U.06)

;...to pch-format
ipch$U.01	=	pchoct(ioct$U.01)
ipch$U.02	=	pchoct(ioct$U.02)
ipch$U.03	=	pchoct(ioct$U.03)
ipch$U.04	=	pchoct(ioct$U.04)
ipch$U.05	=	pchoct(ioct$U.05)
ipch$U.06	=	pchoct(ioct$U.06)

; round off to nearest tone (.01-.11 in pch format)
iTune$U.01	=	(round(ipch$U.01 * 100)) /100
iTune$U.02	=	(round(ipch$U.02 * 100)) /100
iTune$U.03	=	(round(ipch$U.03 * 100)) /100
iTune$U.04	=	(round(ipch$U.04 * 100)) /100
iTune$U.05	=	(round(ipch$U.05 * 100)) /100
iTune$U.06	=	(round(ipch$U.06 * 100)) /100

; Convert back to frequency values
iTune$U.01	=	cpspch(iTune$U.01)
iTune$U.02	=	cpspch(iTune$U.02)
iTune$U.03	=	cpspch(iTune$U.03)
iTune$U.04	=	cpspch(iTune$U.04)
iTune$U.05	=	cpspch(iTune$U.05)
iTune$U.06	=	cpspch(iTune$U.06)

; Set sliders to new values
FLsetVal_i	iTune$U.01, gihPchVal$U.01
FLsetVal_i	iTune$U.02, gihPchVal$U.02
FLsetVal_i	iTune$U.03, gihPchVal$U.03
FLsetVal_i	iTune$U.04, gihPchVal$U.04
FLsetVal_i	iTune$U.05, gihPchVal$U.05
FLsetVal_i	iTune$U.06, gihPchVal$U.06
#
