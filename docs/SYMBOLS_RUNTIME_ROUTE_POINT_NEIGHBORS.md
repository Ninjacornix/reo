# Runtime route point queries and neighbour selection

Static File #1 US research, 2026-11-04. Ten complete original catalog bodies
reviewed. Addresses/offsets/flags hex; distances decimal. Original point/group
names and runtime table population unresolved. No execution, live memory or fixes.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x633790](../recomp/config/output_ovl/o2/o2_00633790_0x633790.cpp) | `count_distinct_signed_neighbor_indices_in_point_record_candidate` | High mechanics; probable role | Reads signedcountbyte1;for eachneighborbyte14+i,scansallpriorneighborsandcountsonlyfirstoccurrence. Signed8loopindices/count/returnretained. Doesnotvalidateindices,activity orgraphconnectivity. |
| [o2 0x633830](../recomp/config/output_ovl/o2/o2_00633830_0x633830.cpp) | `get_runtime_route_point_count_word_candidate` | High mechanics; probable role | Returnsword7445B0. No tablecontentread. |
| [o2 0x633840](../recomp/config/output_ovl/o2/o2_00633840_0x633840.cpp) | `get_runtime_route_point_array_base_candidate` | High mechanics; probable role | Returnsconstant3C3D80. Doesnotallocate,copy orcheckliveness. |
| [o2 0x633850](../recomp/config/output_ovl/o2/o2_00633850_0x633850.cpp) | `read_signed_route_relation_matrix_cell_candidate` | High mechanics; probable role | Returnssignedbyte7441B0+a0+20*a1. No indexboundscheck orclamping. |
| [o2 0x633870](../recomp/config/output_ovl/o2/o2_00633870_0x633870.cpp) | `copy_runtime_route_point_xyz_by_index_candidate` | High mechanics; probable role | Gets633840base;copiesfloatsatbase+40*a1+4/+8/+Cintoa0XYZ. No index/nulldestinationguard. |
| [o2 0x6338B0](../recomp/config/output_ovl/o2/o2_006338B0_0x6338b0.cpp) | `find_nearest_active_route_point_without_group_filter_candidate` | High mechanics; probable role | Tail6338D0(a0XYZ,a1=-1,a2=0,a3=0). Retainsnearestpointdistanceceilingandrecordgates. |
| [o2 0x6338C0](../recomp/config/output_ovl/o2/o2_006338C0_0x6338c0.cpp) | `find_nearest_active_route_point_with_signed_group_selector_candidate` | High mechanics; probable role | Tail6338D0(originalXYZ,originala1group,a2=0,a3=0). Groupselectorisnarrowedsigned8incallee,notunsignedrecordtype. |
| [o2 0x6338D0](../recomp/config/output_ovl/o2/o2_006338D0_0x6338d0.cpp) | `select_nearest_route_point_with_optional_visibility_and_heading_filter_candidate` | High mechanics; probable role | Count633830,base633840. Requiresrecordbyte0nonzero,signedbyte1>0,andgroupselector<0orhalf2match. StrictXYZdistance<initialdecimal10000;flag2requires579980(pointXYZ,inputXYZ,-1,0,out)zeroonlywhencandidatebeatsnearest. Flag1alsoevaluatesclosestpointwithin signed16headingdelta[-1FFF,1FFF]. Returnsheadingcandidateonlyifindex>0;index0fallsbacktonearestindex. Noqualifyingpoint->-1. Nooutwrites. |
| [o2 0x633AA0](../recomp/config/output_ovl/o2/o2_00633AA0_0x633aa0.cpp) | `select_route_point_neighbor_by_group_heading_and_repeat_preference_candidate` | High mechanics; probable role | a0outXYZ,a1inputXYZ,a2signed8previousindex,a3repeatthreshold,t0signed8group,t1signed16heading. Getsnearestmatchingpoint8C0;noresultcopiesinputandreturns-1. Collectsneighbors(signedbytes14+)withmatchinggroupwhenprovided,thenheadingfilter signed16delta[-3FFF,3FFF]. Previousindex<0:randomamongheadingqualifiedif>=2,oneif1,elserandomamonggroupqualified. Nonnegativeprevious:if633790distinctcount==1choosesoriginalfirstneighbor;otherwisepreference/retrybelow. CopieschosenneighborXYZ,returnsindex. Noindices/countboundsenforced. |
| [o2 0x633E90](../recomp/config/output_ovl/o2/o2_00633E90_0x633e90.cpp) | `select_unfiltered_route_neighbor_with_previous_index_retry_preference_candidate` | High mechanics; probable role | a0outXYZ,a1inputXYZ,a2signed8previous,a3repeatthreshold. Nearest8B0;nonecopiesinput/returns-1. Previous<0randomneighbor;otherwise633790distinctcount1selectsfirst. Otherwiserandomneighbor;differentpreviousaccepted,matchingpreviousacceptedonlywhensecondRNG&3<threshold,elseretry. CopieschosenXYZ,returnsindex. Noiterationcapintheoriginalbody;runtimeadmissibilityunknown. |

Runtimepointrecordstride40hex:activitybyte0,signedneighborcountbyte1,
grouphalf2,XYZfloats4/8/C,signedneighborindices14+i. Countword7445B0,
array3C3D80andrelationmatrix7441B0areoutsidefile-backedo2;nonewasreadlive.
Apositivecountisnotproofthatallneighborindicesarevalid.

633AA0 nonnegativepreviousselection preserves this exact ordering:

1. Distinctcount1acceptsoriginalfirstneighborwithoutgroup/headingrestriction.
2. Otherwise ifgroupqualifiedcount==1,acceptsthatneighborimmediately.
3. Withmultiplecandidates,randomheadingqualifiedwhen>=2,soleheadingentry
   when1,elserandomgroupqualified. Withnocandidates,theexistingchoicevalue
   remainsinuse;no fabricatedfallbacktoinputornewguardisclaimed.
4. Ifchosen!=previous,accept. Ifequal,drawRNG&3;acceptwhen<threshold,
   otherwiserepeatfromgroupcandidatechoice. Theoriginalbodyhasnolocalcap.

ThetemporarygrouplistatstackACandheadinglistA8areeachfourbytes;theoriginal
reliesonvalidassetneighborcounts. Tablebounds,callerthresholdranges,termination
andvaliddataareunknownhere;thisisnotaplayerincidentorstallreproduction.
6338D0headingindex0fallbackandtheconditionalvisibilitytestwerecheckedthrough
exactbranch/delayslotpaths. No genericshortestpathorgraphsearchlabelisassigned.
Related [actor6Cresume](SYMBOLS_ACTOR_6C_RELOCATION_RESUME.md).
