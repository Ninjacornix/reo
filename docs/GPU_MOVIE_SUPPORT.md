# MPEG-2 GPU movie support

Checked 2026-11-07. This is a family reference for REO's Windows D3D11 movie
decoder. Codec support alone does not establish that REO's D3D11/Vulkan frame
sharing works. The launcher probes the **selected rendering adapter**, including
when `GRANITE_VULKAN_DEVICE_INDEX` selects a different GPU.

## GPU reference

The examples are consumer GPUs relevant to this project, not an exhaustive list
of mobile, OEM, workstation, or older products. "Probe" means the installed
Windows driver's MPEG-2 VLD implementation must pass the checks below.

| GPU family / examples | MPEG-2 hardware reference | REO GPU movies |
| --- | --- | --- |
| AMD Radeon RX 470/480, RX 570/580 (Polaris) | Available; RX 570 confirmed by the local D3D11 probe | GPU default if probe passes; manual choice available |
| AMD Radeon RX Vega 56/64, Radeon VII; Ryzen integrated Vega (Raven/Picasso/Renoir/Cezanne) | MPEG-2 advertised by AMD's Vega/VCN codec tables [1] | GPU default if probe passes; manual choice available |
| AMD Radeon RX 5500/5600/5700 series (RDNA 1) | MPEG-2 advertised for Navi 1x [2] | GPU default if probe passes; manual choice available |
| AMD Radeon RX 6600/6650, 6700/6750, 6800, 6900/6950 series (RDNA 2, Navi 21/22/23) | MPEG-2 advertised for these media engines [2] | GPU default if probe passes; manual choice available |
| AMD Radeon RX 6400, RX 6500 XT (Navi 24) | MPEG-2 absent from the Beige Goby codec table [2] | CPU default unless the Windows probe passes; manual choice available |
| AMD Radeon 660M/680M (Rembrandt) | MPEG-2 absent from the Yellow Carp codec table [2] | CPU default unless the Windows probe passes; manual choice available |
| AMD Radeon RX 7600/7700/7800/7900 series (RDNA 3, VCN 4) | MPEG-2 absent from AMD's VCN 4 codec tables [3] | CPU default unless the Windows probe passes; manual choice available |
| AMD Radeon RX 9060/9070 series (RDNA 4, VCN 5) | MPEG-2 absent from AMD's VCN 5 codec tables [4]; RX 9060 XT previously observed without a compatible decoder | CPU default unless the Windows probe passes; manual choice available |
| NVIDIA GeForce GTX 600/700 (Kepler), GTX 750/900 (Maxwell), GTX 10 (Pascal), GTX 16 / RTX 20 (Turing), RTX 30 (Ampere), RTX 40 (Ada), RTX 50 (Blackwell) | MPEG-2 supported on products with a decoder in NVIDIA's matrix [5][6] | CPU default; manual GPU choice available (see crash note below) |
| NVIDIA products with no NVDEC engine, e.g. MX570 A | No decoder in NVIDIA's matrix [5] | CPU default; manual GPU choice available |
| Intel HD/Iris/UHD based on Broadwell, Skylake, Kaby/Coffee/Comet Lake, Ice Lake, Tiger/Rocket/Alder/Raptor Lake; Apollo/Gemini/Jasper Lake; Iris Xe MAX (DG1) | MPEG-2 decode in Intel's media-driver matrix [7] | CPU default; manual GPU choice available |
| Intel Arc A310/A380/A580/A750/A770 (Alchemist), B570/B580 (Battlemage); Meteor/Arrow/Lunar/Panther Lake integrated graphics | MPEG-2 decode in Intel's media-driver matrix [7] | CPU default; manual GPU choice available |
| Unlisted GPUs, newer generations, virtual/software adapters | No inferred support from a name or vendor | CPU default; manual GPU choice available; software adapters excluded from the probe |

AMD and Intel Linux driver tables establish the advertised media capabilities,
not Windows DXVA guarantees. AMD Windows drivers may expose a different decode
implementation. Consequently this reference is **not a model-name allowlist or
denylist**: the exact D3D11 adapter/driver result determines codec availability.
MPEG-2 motion compensation or IDCT assistance alone is insufficient for REO.

## Probe and launcher behavior

`launcher/native/movie_decoder_check.cpp` selects the same Vulkan GPU as the
renderer, matches its LUID to a non-software DXGI adapter, and creates a D3D11
video device. It checks both `MPEG2_VLD` and `MPEG2and1_VLD` for:

- NV12 output at 640 x 448.
- Raw VLD bitstream configuration (`ConfigBitstreamRaw == 1`).
- No encryption in all three configuration fields (`GUID_NULL` or DXVA_NoEncrypt).
- At most eight required render targets.
- Successful creation of the decoder.

The launcher and `tools/diagnostics/video_decoder_probe.cpp` share the
configuration acceptance and default recommendation in
`runtime/media/movie_decoder_support.h`. The standalone diagnostic lists every
adapter; its result does not select the game's GPU. Use `--no-wait` to omit its
interactive closing prompt. It also writes `video-decoder-report.txt` beside
the executable.

The launcher's JSON retains `gpu`, `gpuMovies`, and `reason`, and adds
`hardwareMpeg2`: `true` when a compatible decoder can be created, `false` when
none passes, or `null` when GPU selection/device setup prevents checking.
The hardware check runs before the vendor recommendation for every vendor. For example, an
NVIDIA card with a working MPEG-2 decoder reports `hardwareMpeg2: true` while
`gpuMovies: false` recommends CPU decoding. A driver without MPEG-2 reports
the missing compatible decoder even on an unverified vendor.

AMD is the currently verified frame-sharing vendor. NVIDIA defaults to CPU
because a GTX 1070 Ti with driver 582.31 lost the device at the first scenario
movie (project issue #4). Intel and other vendors remain untested. The existing
`REO_GPU_MOVIES_ANY_VENDOR=1` override skips the vendor recommendation; a
compatible MPEG-2 decoder is still required for an automatic GPU default.

The checkbox stays enabled for every probe result, including missing or failed
checks and GPUs without a compatible decoder. Verified GPUs start checked;
previously CPU cases start unchecked. A saved CPU preference stays on CPU.
Changing the checkbox records `GpuMoviesChoice` and overrides the probe at
launch, so users can try GPU decoding without an environment variable. Uncheck
it to return to CPU playback if GPU movies fail.

Older settings used `GpuMovies: true` even when the probe forced CPU playback.
Without an explicit `GpuMoviesChoice`, that legacy value still follows the
probe, and `GpuMovies: false` stays on CPU. Merely checking the GPU or saving
another setting does not record an explicit choice. This prevents an update
from silently switching previously CPU playback to GPU.

## Sources

1. [AMD-authored Linux driver: Vega and Ryzen VCN codec tables](https://github.com/torvalds/linux/blob/master/drivers/gpu/drm/amd/amdgpu/soc15.c).
2. [AMD-authored Linux driver: Navi 1x/2x, Beige Goby and Yellow Carp codec tables](https://github.com/torvalds/linux/blob/master/drivers/gpu/drm/amd/amdgpu/nv.c).
3. [AMD-authored Linux driver: VCN 4 codec tables](https://github.com/torvalds/linux/blob/master/drivers/gpu/drm/amd/amdgpu/soc21.c).
4. [AMD-authored Linux driver: VCN 5 codec tables](https://github.com/torvalds/linux/blob/master/drivers/gpu/drm/amd/amdgpu/soc24.c).
5. [NVIDIA video encode/decode GPU support matrix](https://developer.nvidia.com/video-encode-decode-support-matrix).
6. [NVIDIA NVDEC programming guide, MPEG-1/MPEG-2 capabilities](https://docs.nvidia.com/video-technologies/video-codec-sdk/13.1/nvdec-video-decoder-api-prog-guide/index.html).
7. [Intel media-driver decoding/encoding feature matrix](https://github.com/intel/media-driver#decodingencoding-features).
