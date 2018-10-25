
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

; inc/filelength.inc

;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
;			Get File Length - set sliders
;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

;filelength.inc

#define	FILELENGTH(L)
#
i1		init		1
ktrig		=		k(i1)
ifile		=		i(gkPhrase$L )+1000
ifile		=		(ifile < 1001? 1001: ifile)	; Prevent so that no illegal values are read
iend		table		1, ifile


FLsetVal	ktrig, 0  *  iend, gihFTP$L.00
FLsetVal	ktrig, .17 * iend, gihFTP$L.01
FLsetVal	ktrig, .33 * iend, gihFTP$L.02
FLsetVal	ktrig, .5 *  iend, gihFTP$L.03
FLsetVal	ktrig, .67 * iend, gihFTP$L.04
FLsetVal	ktrig, .83 * iend, gihFTP$L.05
FLsetVal	ktrig, 1  *  iend, gihFTP$L.06
FLsetVal	ktrig, 1  *  iend, gidFileLen$L

FLsetVal_i	i(gkSFSDum$L.01), giSFSDum$L.01
FLsetVal_i	i(gkSFSDum$L.02), giSFSDum$L.02
FLsetVal_i	i(gkSFSDum$L.03), giSFSDum$L.03
FLsetVal_i	i(gkSFSDum$L.04), giSFSDum$L.04
FLsetVal_i	i(gkSFSDum$L.05), giSFSDum$L.05
FLsetVal_i	i(gkSFSDum$L.06), giSFSDum$L.06

; Sets the text that shows the phrases of the poem
iTextCode	= (i(gkPhrase$L ) + 10000)
FLsetText iTextCode, gihText$L

;giend1		=		iend
i1		=		0
turnoff
#
