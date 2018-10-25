;**************************************************************************
;
;		SIX FANTASIES MACHINE, version 0.50beta
;
;**************************************************************************
;A sound making tool based on Six Fantasies on a Poem by Thomas 
;Campion by Paul Lansky. The tool uses LPC analysis/resynthesis 
;and filtering to emulate the range of vocal transformations that 
;can be heard in Lansky's piece.

;Copyright (C ) 2009  Andreas Bergsland
;
;This program is free software: you can redistribute it and/or modify
;it under the terms of the GNU General Public License as published by
;the Free Software Foundation, either version 3 of the License, or
;(at your option ) any later version.
;
;This program is distributed in the hope that it will be useful,
;but WITHOUT ANY WARRANTY; without even the implied warranty of
;MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
;GNU General Public License for more details.
;
;You should have received a copy of the GNU General Public License
;along with this program.  If not, see <http://www.gnu.org/licenses/>.

;***************************************************************************

;"Calculate_durations.inc"

;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
;		Macros for calculating durations and setting values in text boxes
;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#define DURATION(B )
#
; init triggers to zero
ktrigger$B.01	init	0
ktrigger$B.02	init	0
ktrigger$B.03	init	0
ktrigger$B.04	init	0
ktrigger$B.05	init	0
ktrigger$B.06	init	0

ktrigTot$B	init	0



; Calculate duration of segment from file time points and stretch factors
gkdur$B.01	=	(gkFTP$B.01 - gkFTP$B.00 ) * gkSFS$B.01
gkdur$B.02	=	(gkFTP$B.02 - gkFTP$B.01 ) * gkSFS$B.02
gkdur$B.03	=	(gkFTP$B.03 - gkFTP$B.02 ) * gkSFS$B.03
gkdur$B.04	=	(gkFTP$B.04 - gkFTP$B.03 ) * gkSFS$B.04
gkdur$B.05	=	(gkFTP$B.05 - gkFTP$B.04 ) * gkSFS$B.05
gkdur$B.06	=	(gkFTP$B.06 - gkFTP$B.05 ) * gkSFS$B.06

; Do not allow negative durations, instead set to close to zero
gkdur$B.01	=	(gkdur$B.01 < 0? .001: gkdur$B.01 )
gkdur$B.02	=	(gkdur$B.02 < 0? .001: gkdur$B.02 )
gkdur$B.03	=	(gkdur$B.03 < 0? .001: gkdur$B.03 )
gkdur$B.04	=	(gkdur$B.04 < 0? .001: gkdur$B.04 )
gkdur$B.05	=	(gkdur$B.05 < 0? .001: gkdur$B.05 )
gkdur$B.06	=	(gkdur$B.06 < 0? .001: gkdur$B.06 )

; Calculate total duration
gkdur$B		=	gkdur$B.01 + gkdur$B.02 + gkdur$B.03 + gkdur$B.04 + gkdur$B.05 + gkdur$B.06

; Detect change in total duration
; Here only one trigger is necessary - change when possible
ktrigger$B.01	changed	gkdur$B
ktrigger$B.02	changed	gkdur$B
ktrigger$B.03	changed	gkdur$B
ktrigger$B.04	changed	gkdur$B
ktrigger$B.05	changed	gkdur$B
ktrigger$B.06	changed	gkdur$B

ktrigTot$B	changed	gkdur$B

; When changed, trigger instrument 42 that sets values in text boxes
schedkwhen	ktrigger$B.01 , .15, 8, 42, 0.1, .01;, gkdur$B.01
schedkwhen	ktrigger$B.02 , .15, 8, 42, 0.1, .01;, gkdur$B.02
schedkwhen	ktrigger$B.03 , .15, 8, 42, 0.1, .01;, gkdur$B.03
schedkwhen	ktrigger$B.04 , .15, 8, 42, 0.1, .01;, gkdur$B.04
schedkwhen	ktrigger$B.05 , .15, 8, 42, 0.1, .01;, gkdur$B.05
schedkwhen	ktrigger$B.06 , .15, 8, 42, 0.1, .01;, gkdur$B.06

schedkwhen	ktrigTot$B   , .15, 8, 42, 0.2, .01;, gkdur$B.06

; reset triggers
ktrigger$B.01		=	0
ktrigger$B.02		=	0
ktrigger$B.03		=	0
ktrigger$B.04		=	0
ktrigger$B.05		=	0
ktrigger$B.06		=	0

ktrigTot$B		=	0

#


#define	SEGMENTDURATIONS(Y )
#
idur1		=	i(gkdur$Y.01 )
idur2		=	i(gkdur$Y.02 )
idur3		=	i(gkdur$Y.03 )
idur4		=	i(gkdur$Y.04 )
idur5		=	i(gkdur$Y.05 )
idur6		=	i(gkdur$Y.06 )

;print	idur1
;print	idur2
;print	idur3
;print	idur4
;print	idur5
;print	idur6

FLsetVal_i	idur1, giSFSDum$Y.01
FLsetVal_i	idur2, giSFSDum$Y.02
FLsetVal_i	idur3, giSFSDum$Y.03
FLsetVal_i	idur4, giSFSDum$Y.04
FLsetVal_i	idur5, giSFSDum$Y.05
FLsetVal_i	idur6, giSFSDum$Y.06

FLsetVal_i	i(gkdur$Y ), giTotDum$Y
#

#define	TRIGGERDURATIONSET(U)
#
; Is not needed - can be deleted
;gkdur$U		linseg	i(gkdur$U ), p3/2, i(gkdur$U  )+.2, p3/2, i(gkdur$U)
#
