# Pending movie service

Prepared native Sofdec service and transition orchestration. See the
[contract and original evidence](../../../docs/native-media/MOVIE_SERVICE_CONTRACT.md).
Provider effects and media/game ownership still need their integration. This
library does not select production paths or advance clocks itself.

```powershell
python tools/native_reconstruction/movie_service_oracle.py --cohort llvm --output build-native-sjuni/movie-service/<fresh-reference>
python game/native/movie_service/verify.py --compiler <compiler.exe> --reference build-native-sjuni/movie-service/<reference> --output build-native-sjuni/movie-service/<fresh-qualification>
```
