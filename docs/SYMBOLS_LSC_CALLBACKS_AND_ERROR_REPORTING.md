# LSC empty-queue notification and error message callbacks

Static File #1 US research, 2026-11-04. Original **SLUS_207.65**, SHA-256 **06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46**. Full original intervals and queue/module callers reviewed. No callbacks or game executed.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [0x13D3F0](../recomp/config/output/sub_0013D3F0_0x13d3f0.cpp) | `set_LSC_queue_empty_callback_and_two_arguments_candidate` | Confirmed complete setter and retirement consumer | NonNULLa0storescallback21DFD8,args21DFDC/21DFE0=a1/a2;NULLclearsallthree. A global callback, not perinstance registration. |
| [0x13D430](../recomp/config/output/sub_0013D430_0x13d430.cpp) | `notify_LSC_global_queue_empty_callback_if_registered_candidate` | Confirmed retirement trigger and full dispatch | Ifcallback21DFD8nonNULLinvokeswithstoredtwoargs;13D8B0callswhenitsnewqueuecount<=0. Callback does not receive retiring instance unless caller registered it as an argument; return convention not normalized. |
| [0x13D4D0](../recomp/config/output/sub_0013D4D0_0x13d4d0.cpp) | `set_LSC_error_callback_and_context_candidate` | Confirmed full setter and formatter consumer | NonNULLa0->callback21DFE8,a1->context21DFEC;NULLclearsboth. Separate from queue-emptycallback and modulepoolstate. |
| [0x13D4F8](../recomp/config/output/sub_0013D4F8_0x13d4f8.cpp) | `format_LSC_variadic_error_into_shared_buffer_and_notify_candidate` | Confirmed full ABI capture and consumer | Saves integer variadicargumentsa1..t3andfloatingf12..f19;10F880 formats into sharedbuffer21DFF0 from originalformat a0 and argument area. NonNULLcallback21DFE8 receives(context21DFEC,buffer). No explicit destination-capacity argument in this wrapper, no per-thread buffer or guard. Exact formatter bounds and buffer lifetime need lower implementation review; does not itself print, save a report or terminate game. |

Standalone return-only13D588/13D590 receive no semantic credit. Addresses and offsets hexadecimal. Related: [LSC instance/queue service](SYMBOLS_LSC_INSTANCE_LIFETIME_AND_QUEUE_SERVICE.md), [central index](FUNCTION_INDEX.md).
