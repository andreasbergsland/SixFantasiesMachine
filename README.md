# SixFantasiesMachine

The Six Fantasies Machine (SFM) instrument is a tool developed in Csound for producing a range of sounds similar to those found in Paul Lansky’s classic computer music composition Six Fantasies on a Poem by Thomas Campion. I made it as a part of my PhD project, which was finished in 2010. Due to changes in Csound, for many years I couldn't run the software on the recent versions, which was a bit sad. However, I have now (October 2018) gone through the code again and got it up and running on Csound 6.12 on OSX.

To run: 
To run, install Csound version 6.12 (if not already installeed), download/clone from github, and then run it from the terminal after having navigated to the location where the files are downloaded:

csound --omacro:Path=/Full/Path/Here SFM.csd

Lansky's piece was made in 1979 using dominantly LPC, linear predicative coding, and comb filters. The piece was made, with some exceptions, from a sound recording of Lansky’s wife, Hannah MacKey reading Campion’s poem. The five first movements in the piece each explore different aspects of the voice and different techniques. LPC is an analysis/resynthesis technology, promising at the time of composition, that calculates the filter coefficients from a speech as well as the fundamental frequency and the amplitude of the speech signal. It can be used in combination with a buzz and a noise source controlled by the parameters for analysis to produce a speech signal. Through this technique the fundamental frequency, the spectral envelope, the pitch values and the duration can be controlled independently from each other. Lansky also used double comb filters extensively in the third and fifth movements, where he put together banks of comb filters that could produce complex spectra.

The analysis files for SFM was made by recording the voice of actress Nancy Helms imitating Hannah MacKey’s reading that is presented in the last of the fantasies. Five recordings were made and the best individual phrases were selected. Due to recording levels set to low the resulting sound files had to be increased in gain by 17.3dB’s. Then, the sound files were resampled and analyzed using lpanal, the LPC analysis utility in csound. These files are provided in the instrument.

SFM has eight voices that can be manipulated individually. The resulting sound can be written to sound files if desired. Thus, the instrument can be used as an exploration of sounds in the footsteps of Lansky, and as a tool for composition.
