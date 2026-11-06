# Owned LSC filename queue

This native core preserves the admitted original queue/control behavior with
immutable owned names. All callers require external serialization. Notification
callbacks may enqueue or mutate controls; nested service returns `busy`.
`LowerFile` remains an explicit control port and does not establish an actual
source-worker lifetime or grant file-read authority.

Read the [contract](../../../docs/native-media/LSC_QUEUE_CONTRACT.md) and
[evidence](../../../docs/native-media/LSC_QUEUE_IMPLEMENTATION.md).
`manifest.json` pins the tested code; `qualification.json` pins the retained
original/native/negative and parent results.

```powershell
python game/native/lsc_queue/verify.py --cxx C:/msys64/mingw64/bin/g++.exe --output build-native-sjuni/lsc-queue/new-gcc-run
```

Use a fresh scoped output. The verifier compares 339 operations with the
pre-native original corpus, checks ownership and detects four counterfactual
variants. It opens neither the game nor a real audio device.
