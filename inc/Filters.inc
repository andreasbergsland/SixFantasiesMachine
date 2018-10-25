
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

; inc/Filters.inc

#define FILTER(Voice'Filter)
#

adry$Voice	zar	$Voice

iFilterType$Voice._$Filter 	=	i(gkFilterType$Voice._$Filter )
iFilterPitch$Voice._$Filter	=	i(gkFilterPitch$Voice._$Filter )
iDecayTime$Voice._$Filter	=	i(gkDecayTime$Voice._$Filter )
iBand$Voice._$Filter		=	i(gkBand$Voice._$Filter )
iFilterGain$Voice._$Filter	=	i(gkFilterGain$Voice._$Filter )
iFilterOn$Voice._$Filter	=	i(gkFilterOn$Voice._$Filter )

iPitch$Voice._$Filter	=	cpspch(iFilterPitch$Voice._$Filter )
iFreq$Voice._$Filter	=	(iFilterPitch$Voice._$Filter < 20? iPitch$Voice._$Filter : iFilterPitch$Voice._$Filter )
idelt$Voice._$Filter 	=	1 / iFreq$Voice._$Filter

;printks	"idelt=%5.5f \n", 1, idelt$Voice._$Filter

if	(iFilterType$Voice._$Filter ==0)	then
aComb	comb	adry$Voice , iDecayTime$Voice._$Filter , idelt$Voice._$Filter
aComb2	comb	aComb,      iDecayTime$Voice._$Filter , idelt$Voice._$Filter
afilt$Voice._$Filter	=	aComb2
igain$Voice._$Filter	=	iFilterGain$Voice._$Filter
igain$Voice._$Filter	=	igain$Voice._$Filter * 0.0001
;print	igain$Voice._$Filter

elseif 	(iFilterType$Voice._$Filter ==1) then
aBandP	butbp	adry$Voice , iFreq$Voice._$Filter , iBand$Voice._$Filter * iFreq$Voice._$Filter
aBandP2	butbp	aBandP,     iFreq$Voice._$Filter , iBand$Voice._$Filter * iFreq$Voice._$Filter
afilt$Voice._$Filter	=	aBandP2
igain$Voice._$Filter	=	iFilterGain$Voice._$Filter

elseif	(iFilterType$Voice._$Filter ==2) then
aBandP	butbp	adry$Voice , iFreq$Voice._$Filter , iBand$Voice._$Filter * iFreq$Voice._$Filter
aCombi	comb	aBandP, iDecayTime$Voice._$Filter , idelt$Voice._$Filter
aCombi2	comb	aCombi, iDecayTime$Voice._$Filter , idelt$Voice._$Filter

afilt$Voice._$Filter	=	aCombi2
igain$Voice._$Filter	=	iFilterGain$Voice._$Filter * 0.001

endif

aFilter$Voice._$Filter	=	igain$Voice._$Filter * afilt$Voice._$Filter * iFilterOn$Voice._$Filter
#

#define FILTERMACRO(VC)
#
$FILTER($VC'1)
$FILTER($VC'2)
$FILTER($VC'3)
$FILTER($VC'4)
$FILTER($VC'5)
$FILTER($VC'6)
$FILTER($VC'7)
$FILTER($VC'8)
$FILTER($VC'9)
#

