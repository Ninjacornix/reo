# Resident DVCI and HTCI configuration/query facades

Static File #1 US original resident ELF, 2026-11-05, SHA-256 `06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46`. Eightcompleteoriginalintervalsreadwithargument/delay-slotrouting. NoI/O,game,buildorhostconfigurationchange.

[TypedDVCI callees](SYMBOLS_DVCI_PATH_FILELIST_AND_DISC_LOOKUP.md), [HTCI cachedmetadata](SYMBOLS_HTCI_CACHE_FILELIST_AND_PATH_CONFIGURATION.md), [seekerroradapter](SYMBOLS_SRD_HOST_OPTIONS_DISC_SEEK_AND_HTCI_COMPLETION.md). Numericfieldsarehexadecimal.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [0x1311F0](../recomp/config/output/sub_001311F0_0x1311f0.cpp) | `adapt_DVCI_supplied_filelist_text_descriptor_or_clear_default` | Confirmed complete facade to separately reviewed typed contract | Nonnullconfiga0 forwards13AC60(originala1input,originala2bytes,config8output,configCoutputBytes,config4width),returnsresult. NULL calls13AAB0(NULL,0,0,0)andreturnsinitialized0,discardingchildresult. Notdiscreaduntilchildrole. |
| [0x131258](../recomp/config/output/sub_00131258_0x131258.cpp) | `configure_DVCI_mode_triplet_option_and_path_prefix_from_descriptor` | Confirmed complete facade to separately reviewed typed contract | Nonnullconfig:13ADF0(words8/C/10,word4),13AE10(word0);NULL passesallzerosandclearsstoredprefix. NoI/Ostarted;returninheritsprefixcallee. |
| [0x1312C0](../recomp/config/output/sub_001312C0_0x1312c0.cpp) | `query_DVCI_filelist_nonzero_metadata_word_public_adapter` | Confirmed complete facade to separately reviewed typed contract | Unchangedtail13ADC8;returnsbooleanonresolvedfirstword,notgeneralfileexists/positivefilesize. |
| [0x1312D8](../recomp/config/output/sub_001312D8_0x1312d8.cpp) | `set_DVCI_disc_search_option_public_adapter` | Confirmed complete facade to separately reviewed typed contract | Unchangedtail13A058;validunsigned0/1preserved,othersbecome0. Noimmediatediscoperation. |
| [0x1312F0](../recomp/config/output/sub_001312F0_0x1312f0.cpp) | `get_DVCI_disc_search_option_public_adapter` | Confirmed complete facade to separately reviewed typed contract | Unchangedtail13A078,returnsglobal21CBEC. |
| [0x131308](../recomp/config/output/sub_00131308_0x131308.cpp) | `query_DVCI_guarded_disc_seek_error_public_adapter` | Confirmed complete facade to separately reviewed typed contract | Unchangedtail13AEE8then138360reviewedseekerror. Addsnowait,read,cachelookuporerrornormalization. |
| [0x131320](../recomp/config/output/sub_00131320_0x131320.cpp) | `forward_DVCI_error_callback_text_to_CRI_publisher` | Confirmed complete facade to separately reviewed typed contract | a1->a0,tail1280D0;originalcontextdiscarded. SameactualtextpublicationrouteasotherCRIerroradapterswithdistinctentryidentity. |
| [0x131478](../recomp/config/output/sub_00131478_0x131478.cpp) | `query_HTCI_cached_filename_nonzero_size_public_adapter` | Confirmed complete facade to separately reviewed typed contract | Unchangedtail13C9C0cachedmetadataquery;missing/emptysizebothfalse,nostat/open. |

Thinbodiesdo notaddvalidation,exceptionmappingorhostpathsemanticsbeyondtheircallees. Null-descriptorreturnbehaviorisretainedindependentlyfromnonnullconfiguration. Originalguestcachesanddiscoptionsdonotprovenativereadlatency.

Audit: 8 bodies, 81 owned instruction words matched; 0 omitted aligned zero/NOP words, zero omitted nonzero words.
