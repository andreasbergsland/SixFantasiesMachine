
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

;write_presets.inc

;*************************************************************************************
;		Write presets
;*************************************************************************************


#define	PRESETWRITE(Q)
#
	tablew 	i(gkActive$Q ), 	$Q.01 , ifn 
	tablew	i(gkVol$Q ), 	$Q.02, ifn
	tablew	i(gkChorus$Q ), 	$Q.03, ifn
	tablew	i(gkRevMix$Q ), 	$Q.04, ifn
	tablew	i(gkPan$Q ), 	$Q.05, ifn
	tablew   	i(gkNoiz$Q ),	$Q.06, ifn

	tablew	i(gkFTP$Q.00), 	$Q.11, ifn
	tablew	i(gkFTP$Q.01), 	$Q.12, ifn
	tablew	i(gkFTP$Q.02), 	$Q.13, ifn
	tablew	i(gkFTP$Q.03), 	$Q.14, ifn
	tablew	i(gkFTP$Q.04), 	$Q.15, ifn
	tablew	i(gkFTP$Q.05), 	$Q.16, ifn
	tablew	i(gkFTP$Q.06), 	$Q.17, ifn

	tablew	i(gkSFS$Q.01), 	$Q.121, ifn
	tablew	i(gkSFS$Q.02), 	$Q.122, ifn	
	tablew	i(gkSFS$Q.03), 	$Q.123, ifn	
	tablew	i(gkSFS$Q.04), 	$Q.124, ifn	
	tablew	i(gkSFS$Q.05), 	$Q.125, ifn	
	tablew	i(gkSFS$Q.06), 	$Q.126, ifn	
	
	tablew	i(gkPchVal$Q.01),$Q.31, ifn
	tablew	i(gkPchVal$Q.02),$Q.32, ifn
	tablew	i(gkPchVal$Q.03),$Q.33, ifn
	tablew	i(gkPchVal$Q.04),$Q.34, ifn
	tablew	i(gkPchVal$Q.05),$Q.35, ifn
	tablew	i(gkPchVal$Q.06),$Q.36, ifn

	tablew	i(gkDelay$Q ),	$Q.41, ifn
	tablew	i(gkRange$Q ),	$Q.42, ifn
	tablew	i(gkTransp$Q ),	$Q.43, ifn
	tablew	i(gkNoise$Q ),	$Q.44, ifn
	tablew	i(gkPchSrc$Q ),	$Q.45, ifn
	tablew	i(gkPort$Q ), 	$Q.46, ifn
	tablew	i(gkFrqShift$Q ),$Q.47, ifn

	tablew	i(gkPhrase$Q ) +1000, 	$Q.50, ifn
	
#
