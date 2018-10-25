
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

; inc/Filters_read_parameters.inc


#define FILTERPARAMASSIGN
#
gkFilterMix1	tab	1, 500
gkFilterMix2	tab	2, 500
gkFilterMix3	tab	3, 500
gkFilterMix4	tab	4, 500
gkFilterMix5	tab	5, 500
gkFilterMix6	tab	6, 500
gkFilterMix7	tab	7, 500
gkFilterMix8	tab	8, 500

iFilterType1_1	tab_i	9	, 500
iFilterPitch1_1	tab_i	17	, 500
iDecayTime1_1	tab_i	25	, 500
iBand1_1	tab_i	33	, 500
iFilterGain1_1	tab_i	41	, 500
iFilterType1_2	tab_i	49	, 500
iFilterPitch1_2	tab_i	57	, 500
iDecayTime1_2	tab_i	65	, 500
iBand1_2	tab_i	73	, 500
iFilterGain1_2	tab_i	81	, 500
iFilterType1_3	tab_i	89	, 500
iFilterPitch1_3	tab_i	97	, 500
iDecayTime1_3	tab_i	105	, 500
iBand1_3	tab_i	113	, 500
iFilterGain1_3	tab_i	121	, 500
iFilterType1_4	tab_i	129	, 500
iFilterPitch1_4	tab_i	137	, 500
iDecayTime1_4	tab_i	145	, 500
iBand1_4	tab_i	153	, 500
iFilterGain1_4	tab_i	161	, 500
iFilterType1_5	tab_i	169	, 500
iFilterPitch1_5	tab_i	177	, 500
iDecayTime1_5	tab_i	185	, 500
iBand1_5	tab_i	193	, 500
iFilterGain1_5	tab_i	201	, 500
iFilterType1_6	tab_i	209	, 500
iFilterPitch1_6	tab_i	217	, 500
iDecayTime1_6	tab_i	225	, 500
iBand1_6	tab_i	233	, 500
iFilterGain1_6	tab_i	241	, 500
iFilterType1_7	tab_i	249	, 500
iFilterPitch1_7	tab_i	257	, 500
iDecayTime1_7	tab_i	265	, 500
iBand1_7	tab_i	273	, 500
iFilterGain1_7	tab_i	281	, 500
iFilterType1_8	tab_i	289	, 500
iFilterPitch1_8	tab_i	297	, 500
iDecayTime1_8	tab_i	305	, 500
iBand1_8	tab_i	313	, 500
iFilterGain1_8	tab_i	321	, 500
iFilterType1_9	tab_i	329	, 500
iFilterPitch1_9	tab_i	337	, 500
iDecayTime1_9	tab_i	345	, 500
iBand1_9	tab_i	353	, 500
iFilterGain1_9	tab_i	361	, 500
iFilterType2_1	tab_i	10	, 500
iFilterPitch2_1	tab_i	18	, 500
iDecayTime2_1	tab_i	26	, 500
iBand2_1	tab_i	34	, 500
iFilterGain2_1	tab_i	42	, 500
iFilterType2_2	tab_i	50	, 500
iFilterPitch2_2	tab_i	58	, 500
iDecayTime2_2	tab_i	66	, 500
iBand2_2	tab_i	74	, 500
iFilterGain2_2	tab_i	82	, 500
iFilterType2_3	tab_i	90	, 500
iFilterPitch2_3	tab_i	98	, 500
iDecayTime2_3	tab_i	106	, 500
iBand2_3	tab_i	114	, 500
iFilterGain2_3	tab_i	122	, 500
iFilterType2_4	tab_i	130	, 500
iFilterPitch2_4	tab_i	138	, 500
iDecayTime2_4	tab_i	146	, 500
iBand2_4	tab_i	154	, 500
iFilterGain2_4	tab_i	162	, 500
iFilterType2_5	tab_i	170	, 500
iFilterPitch2_5	tab_i	178	, 500
iDecayTime2_5	tab_i	186	, 500
iBand2_5	tab_i	194	, 500
iFilterGain2_5	tab_i	202	, 500
iFilterType2_6	tab_i	210	, 500
iFilterPitch2_6	tab_i	218	, 500
iDecayTime2_6	tab_i	226	, 500
iBand2_6	tab_i	234	, 500
iFilterGain2_6	tab_i	242	, 500
iFilterType2_7	tab_i	250	, 500
iFilterPitch2_7	tab_i	258	, 500
iDecayTime2_7	tab_i	266	, 500
iBand2_7	tab_i	274	, 500
iFilterGain2_7	tab_i	282	, 500
iFilterType2_8	tab_i	290	, 500
iFilterPitch2_8	tab_i	298	, 500
iDecayTime2_8	tab_i	306	, 500
iBand2_8	tab_i	314	, 500
iFilterGain2_8	tab_i	322	, 500
iFilterType2_9	tab_i	330	, 500
iFilterPitch2_9	tab_i	338	, 500
iDecayTime2_9	tab_i	346	, 500
iBand2_9	tab_i	354	, 500
iFilterGain2_9	tab_i	362	, 500
iFilterType3_1	tab_i	11	, 500
iFilterPitch3_1	tab_i	19	, 500
iDecayTime3_1	tab_i	27	, 500
iBand3_1	tab_i	35	, 500
iFilterGain3_1	tab_i	43	, 500
iFilterType3_2	tab_i	51	, 500
iFilterPitch3_2	tab_i	59	, 500
iDecayTime3_2	tab_i	67	, 500
iBand3_2	tab_i	75	, 500
iFilterGain3_2	tab_i	83	, 500
iFilterType3_3	tab_i	91	, 500
iFilterPitch3_3	tab_i	99	, 500
iDecayTime3_3	tab_i	107	, 500
iBand3_3	tab_i	115	, 500
iFilterGain3_3	tab_i	123	, 500
iFilterType3_4	tab_i	131	, 500
iFilterPitch3_4	tab_i	139	, 500
iDecayTime3_4	tab_i	147	, 500
iBand3_4	tab_i	155	, 500
iFilterGain3_4	tab_i	163	, 500
iFilterType3_5	tab_i	171	, 500
iFilterPitch3_5	tab_i	179	, 500
iDecayTime3_5	tab_i	187	, 500
iBand3_5	tab_i	195	, 500
iFilterGain3_5	tab_i	203	, 500
iFilterType3_6	tab_i	211	, 500
iFilterPitch3_6	tab_i	219	, 500
iDecayTime3_6	tab_i	227	, 500
iBand3_6	tab_i	235	, 500
iFilterGain3_6	tab_i	243	, 500
iFilterType3_7	tab_i	251	, 500
iFilterPitch3_7	tab_i	259	, 500
iDecayTime3_7	tab_i	267	, 500
iBand3_7	tab_i	275	, 500
iFilterGain3_7	tab_i	283	, 500
iFilterType3_8	tab_i	291	, 500
iFilterPitch3_8	tab_i	299	, 500
iDecayTime3_8	tab_i	307	, 500
iBand3_8	tab_i	315	, 500
iFilterGain3_8	tab_i	323	, 500
iFilterType3_9	tab_i	331	, 500
iFilterPitch3_9	tab_i	339	, 500
iDecayTime3_9	tab_i	347	, 500
iBand3_9	tab_i	355	, 500
iFilterGain3_9	tab_i	363	, 500
iFilterType4_1	tab_i	12	, 500
iFilterPitch4_1	tab_i	20	, 500
iDecayTime4_1	tab_i	28	, 500
iBand4_1	tab_i	36	, 500
iFilterGain4_1	tab_i	44	, 500
iFilterType4_2	tab_i	52	, 500
iFilterPitch4_2	tab_i	60	, 500
iDecayTime4_2	tab_i	68	, 500
iBand4_2	tab_i	76	, 500
iFilterGain4_2	tab_i	84	, 500
iFilterType4_3	tab_i	92	, 500
iFilterPitch4_3	tab_i	100	, 500
iDecayTime4_3	tab_i	108	, 500
iBand4_3	tab_i	116	, 500
iFilterGain4_3	tab_i	124	, 500
iFilterType4_4	tab_i	132	, 500
iFilterPitch4_4	tab_i	140	, 500
iDecayTime4_4	tab_i	148	, 500
iBand4_4	tab_i	156	, 500
iFilterGain4_4	tab_i	164	, 500
iFilterType4_5	tab_i	172	, 500
iFilterPitch4_5	tab_i	180	, 500
iDecayTime4_5	tab_i	188	, 500
iBand4_5	tab_i	196	, 500
iFilterGain4_5	tab_i	204	, 500
iFilterType4_6	tab_i	212	, 500
iFilterPitch4_6	tab_i	220	, 500
iDecayTime4_6	tab_i	228	, 500
iBand4_6	tab_i	236	, 500
iFilterGain4_6	tab_i	244	, 500
iFilterType4_7	tab_i	252	, 500
iFilterPitch4_7	tab_i	260	, 500
iDecayTime4_7	tab_i	268	, 500
iBand4_7	tab_i	276	, 500
iFilterGain4_7	tab_i	284	, 500
iFilterType4_8	tab_i	292	, 500
iFilterPitch4_8	tab_i	300	, 500
iDecayTime4_8	tab_i	308	, 500
iBand4_8	tab_i	316	, 500
iFilterGain4_8	tab_i	324	, 500
iFilterType4_9	tab_i	332	, 500
iFilterPitch4_9	tab_i	340	, 500
iDecayTime4_9	tab_i	348	, 500
iBand4_9	tab_i	356	, 500
iFilterGain4_9	tab_i	364	, 500
iFilterType5_1	tab_i	13	, 500
iFilterPitch5_1	tab_i	21	, 500
iDecayTime5_1	tab_i	29	, 500
iBand5_1	tab_i	37	, 500
iFilterGain5_1	tab_i	45	, 500
iFilterType5_2	tab_i	53	, 500
iFilterPitch5_2	tab_i	61	, 500
iDecayTime5_2	tab_i	69	, 500
iBand5_2	tab_i	77	, 500
iFilterGain5_2	tab_i	85	, 500
iFilterType5_3	tab_i	93	, 500
iFilterPitch5_3	tab_i	101	, 500
iDecayTime5_3	tab_i	109	, 500
iBand5_3	tab_i	117	, 500
iFilterGain5_3	tab_i	125	, 500
iFilterType5_4	tab_i	133	, 500
iFilterPitch5_4	tab_i	141	, 500
iDecayTime5_4	tab_i	149	, 500
iBand5_4	tab_i	157	, 500
iFilterGain5_4	tab_i	165	, 500
iFilterType5_5	tab_i	173	, 500
iFilterPitch5_5	tab_i	181	, 500
iDecayTime5_5	tab_i	189	, 500
iBand5_5	tab_i	197	, 500
iFilterGain5_5	tab_i	205	, 500
iFilterType5_6	tab_i	213	, 500
iFilterPitch5_6	tab_i	221	, 500
iDecayTime5_6	tab_i	229	, 500
iBand5_6	tab_i	237	, 500
iFilterGain5_6	tab_i	245	, 500
iFilterType5_7	tab_i	253	, 500
iFilterPitch5_7	tab_i	261	, 500
iDecayTime5_7	tab_i	269	, 500
iBand5_7	tab_i	277	, 500
iFilterGain5_7	tab_i	285	, 500
iFilterType5_8	tab_i	293	, 500
iFilterPitch5_8	tab_i	301	, 500
iDecayTime5_8	tab_i	309	, 500
iBand5_8	tab_i	317	, 500
iFilterGain5_8	tab_i	325	, 500
iFilterType5_9	tab_i	333	, 500
iFilterPitch5_9	tab_i	341	, 500
iDecayTime5_9	tab_i	349	, 500
iBand5_9	tab_i	357	, 500
iFilterGain5_9	tab_i	365	, 500
iFilterType6_1	tab_i	14	, 500
iFilterPitch6_1	tab_i	22	, 500
iDecayTime6_1	tab_i	30	, 500
iBand6_1	tab_i	38	, 500
iFilterGain6_1	tab_i	46	, 500
iFilterType6_2	tab_i	54	, 500
iFilterPitch6_2	tab_i	62	, 500
iDecayTime6_2	tab_i	70	, 500
iBand6_2	tab_i	78	, 500
iFilterGain6_2	tab_i	86	, 500
iFilterType6_3	tab_i	94	, 500
iFilterPitch6_3	tab_i	102	, 500
iDecayTime6_3	tab_i	110	, 500
iBand6_3	tab_i	118	, 500
iFilterGain6_3	tab_i	126	, 500
iFilterType6_4	tab_i	134	, 500
iFilterPitch6_4	tab_i	142	, 500
iDecayTime6_4	tab_i	150	, 500
iBand6_4	tab_i	158	, 500
iFilterGain6_4	tab_i	166	, 500
iFilterType6_5	tab_i	174	, 500
iFilterPitch6_5	tab_i	182	, 500
iDecayTime6_5	tab_i	190	, 500
iBand6_5	tab_i	198	, 500
iFilterGain6_5	tab_i	206	, 500
iFilterType6_6	tab_i	214	, 500
iFilterPitch6_6	tab_i	222	, 500
iDecayTime6_6	tab_i	230	, 500
iBand6_6	tab_i	238	, 500
iFilterGain6_6	tab_i	246	, 500
iFilterType6_7	tab_i	254	, 500
iFilterPitch6_7	tab_i	262	, 500
iDecayTime6_7	tab_i	270	, 500
iBand6_7	tab_i	278	, 500
iFilterGain6_7	tab_i	286	, 500
iFilterType6_8	tab_i	294	, 500
iFilterPitch6_8	tab_i	302	, 500
iDecayTime6_8	tab_i	310	, 500
iBand6_8	tab_i	318	, 500
iFilterGain6_8	tab_i	326	, 500
iFilterType6_9	tab_i	334	, 500
iFilterPitch6_9	tab_i	342	, 500
iDecayTime6_9	tab_i	350	, 500
iBand6_9	tab_i	358	, 500
iFilterGain6_9	tab_i	366	, 500
iFilterType7_1	tab_i	15	, 500
iFilterPitch7_1	tab_i	23	, 500
iDecayTime7_1	tab_i	31	, 500
iBand7_1	tab_i	39	, 500
iFilterGain7_1	tab_i	47	, 500
iFilterType7_2	tab_i	55	, 500
iFilterPitch7_2	tab_i	63	, 500
iDecayTime7_2	tab_i	71	, 500
iBand7_2	tab_i	79	, 500
iFilterGain7_2	tab_i	87	, 500
iFilterType7_3	tab_i	95	, 500
iFilterPitch7_3	tab_i	103	, 500
iDecayTime7_3	tab_i	111	, 500
iBand7_3	tab_i	119	, 500
iFilterGain7_3	tab_i	127	, 500
iFilterType7_4	tab_i	135	, 500
iFilterPitch7_4	tab_i	143	, 500
iDecayTime7_4	tab_i	151	, 500
iBand7_4	tab_i	159	, 500
iFilterGain7_4	tab_i	167	, 500
iFilterType7_5	tab_i	175	, 500
iFilterPitch7_5	tab_i	183	, 500
iDecayTime7_5	tab_i	191	, 500
iBand7_5	tab_i	199	, 500
iFilterGain7_5	tab_i	207	, 500
iFilterType7_6	tab_i	215	, 500
iFilterPitch7_6	tab_i	223	, 500
iDecayTime7_6	tab_i	231	, 500
iBand7_6	tab_i	239	, 500
iFilterGain7_6	tab_i	247	, 500
iFilterType7_7	tab_i	255	, 500
iFilterPitch7_7	tab_i	263	, 500
iDecayTime7_7	tab_i	271	, 500
iBand7_7	tab_i	279	, 500
iFilterGain7_7	tab_i	287	, 500
iFilterType7_8	tab_i	295	, 500
iFilterPitch7_8	tab_i	303	, 500
iDecayTime7_8	tab_i	311	, 500
iBand7_8	tab_i	319	, 500
iFilterGain7_8	tab_i	327	, 500
iFilterType7_9	tab_i	335	, 500
iFilterPitch7_9	tab_i	343	, 500
iDecayTime7_9	tab_i	351	, 500
iBand7_9	tab_i	359	, 500
iFilterGain7_9	tab_i	367	, 500
iFilterType8_1	tab_i	16	, 500
iFilterPitch8_1	tab_i	24	, 500
iDecayTime8_1	tab_i	32	, 500
iBand8_1	tab_i	40	, 500
iFilterGain8_1	tab_i	48	, 500
iFilterType8_2	tab_i	56	, 500
iFilterPitch8_2	tab_i	64	, 500
iDecayTime8_2	tab_i	72	, 500
iBand8_2	tab_i	80	, 500
iFilterGain8_2	tab_i	88	, 500
iFilterType8_3	tab_i	96	, 500
iFilterPitch8_3	tab_i	104	, 500
iDecayTime8_3	tab_i	112	, 500
iBand8_3	tab_i	120	, 500
iFilterGain8_3	tab_i	128	, 500
iFilterType8_4	tab_i	136	, 500
iFilterPitch8_4	tab_i	144	, 500
iDecayTime8_4	tab_i	152	, 500
iBand8_4	tab_i	160	, 500
iFilterGain8_4	tab_i	168	, 500
iFilterType8_5	tab_i	176	, 500
iFilterPitch8_5	tab_i	184	, 500
iDecayTime8_5	tab_i	192	, 500
iBand8_5	tab_i	200	, 500
iFilterGain8_5	tab_i	208	, 500
iFilterType8_6	tab_i	216	, 500
iFilterPitch8_6	tab_i	224	, 500
iDecayTime8_6	tab_i	232	, 500
iBand8_6	tab_i	240	, 500
iFilterGain8_6	tab_i	248	, 500
iFilterType8_7	tab_i	256	, 500
iFilterPitch8_7	tab_i	264	, 500
iDecayTime8_7	tab_i	272	, 500
iBand8_7	tab_i	280	, 500
iFilterGain8_7	tab_i	288	, 500
iFilterType8_8	tab_i	296	, 500
iFilterPitch8_8	tab_i	304	, 500
iDecayTime8_8	tab_i	312	, 500
iBand8_8	tab_i	320	, 500
iFilterGain8_8	tab_i	328	, 500
iFilterType8_9	tab_i	336	, 500
iFilterPitch8_9	tab_i	344	, 500
iDecayTime8_9	tab_i	352	, 500
iBand8_9	tab_i	360	, 500
iFilterGain8_9	tab_i	368	, 500

#