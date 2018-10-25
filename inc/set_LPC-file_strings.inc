
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

;set_LPC-file_strings.inc

;Set string codes for substitution of numbers 1001 - 1021 of LPC files
strset		1001, "lpc/Rose_cheeked_Lawra_17,3dB_14k-cut[i]_20_500.lp" ; A pause of 0.063s of the original recording was cut out to avoid silence in the analysis file
strset		1002, "lpc/come_lpfilt7kHz_17,3db_14kHz_500_20.lp"
strset		1003, "lpc/Sing_thou_smoothly_17,3dB_lpfilt7kHz_14k_20_500.lp"
strset		1004, "lpc/Silent_Music_17,3dB_lp7k_14k_20_500.lp"; Analysis file not satisfactory
strset		1005, "lpc/Either other_17,3dB_lp7k_14k_20_500.lp"
strset		1006, "lpc/Sweetly gracing_17,3dB_lp7k_14k_20_500.lp"
strset		1007, "lpc/Lovely formes_17,3dB_lp7k_14k_20_500.lp"
strset		1008, "lpc/From consent_17,3dB_lp7k_14k_24_500.lp"
strset		1009, "lpc/Heaven is music_17,3dB_lp7k_14k_20_500.lp"
strset		1010, "lpc/And thy beuties birth_17,3dB_lp7k_14k_20_500.lp"
strset		1011, "lpc/Is heavenly_17,3dB_lp7k_14k_20_500.lp"
strset		1012, "lpc/These_dull_notes_17,3dB_lp7k_14k_18_500.lp"
strset		1013, "lpc/Discords_neede_23dB_lp7k_14k_24_500.lp"; ierr value set to .02
strset		1014, "lpc/Only beuty_23dB_lp7k_14k_20_500.lp"; Analysis file not saisfactory
strset		1015, "lpc/Knows_no_discord_17,3dB_lp7k_14k_20_500.lp"
strset		1016, "lpc/But_still_17,3dB_lp7k_14k_18_500.lp"
strset		1017, "lpc/Moves_delight_cut_17,3dB_lp7k_14k_18_500.lp"; Analysis file not saisfactory
strset		1018, "lpc/Like_clear_springs_17,3dB_lp7k_14k_20_500.lp"; ierr set to .03
strset		1019, "lpc/Ever_perfect_17,3dB_lp7k_14k_24_500.lp"
strset		1020, "lpc/Ever_in_themselves_17,3dB_lp7k_14k_20_500.lp"
strset		1021, "lpc/Eternall_17,3dB_lp7k_14k_20_500.lp"
