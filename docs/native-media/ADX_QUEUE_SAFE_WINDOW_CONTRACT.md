# Native decode windows with queued PCM

Status: contract before implementation. This is a native scheduling extension,
separate from the original-qualified R2 request calculation. It changes neither
the ADX codec nor the declared sample sequence. Link only one window revision
into an executable.

The full imported regular-loop player exposed a real storage refusal at
NETBIO01.DAT/1/36 with both compilers. Its second loop had 996 valid samples left;
the original request calculation selected 1024 raw samples. The actual free
grant was 2040 bytes at offset8, followed by queued PCM. A 2048-byte raw store
would overwrite eight queued bytes. The PCM guard correctly refused it. Failed
full runs and their original sources remain in the local artifact directory.

R3 must preflight the actual retained PCM reservation before executing the codec.
The store supplies a pure admission query using exactly the same physical
interval checks as stage. It considers raw writes, corrected wrap, publication
mirrors, queued samples and held readers. Refusal changes no bytes or credit.
The native decoder chooses the largest whole ADPCM group count within the old
request that passes that check, reducing it at most76 times. Production and
publication counts are recomputed from that candidate's actual remaining-sample
budget; the final padding correction applies only when reaching the budget.

If no group fits, return both actual reservations without publication or codec
execution and report backpressure. Later transfer/render progress may create
space. Never discard samples, overwrite queued bytes, remove a safety check,
invent encoded credit or reset predictor/source state to force progress.

Non-conflicting R2 transactions must retain their calculations and bytes. This
does not claim identical intermediate service counts for the newly admitted
queue-constrained domain. Qualification requires retained two-cycle asset
digests, raw-clock/consumed-ledger agreement, bounded source/output retirement,
the prior PCM and decoder suites, and a negative control restoring the unsafe
request selection. There is no game or real-device claim from model rendering.
