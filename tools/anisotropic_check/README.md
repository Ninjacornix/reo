# GPU anisotropic texture filtering check

Build the current native renderer first, then close the game and run:

```powershell
powershell -NoProfile -ExecutionPolicy Bypass -File tools/anisotropic_check/run.ps1
```

This uses the production GS renderer and Vulkan device, without an ISO or game code. It renders a striped texture at 1× (off), 2×, 4×, 8× and 16×. It checks that the oblique 3D texture changes, that 16× reduces alias energy by at least 80%, and that fixed-UV triangles, sprites and isotropic magnification remain byte-identical. Raw RGBA outputs and `result.json` go under `build-ninja/anisotropic-check`.

The enhancement uses a Vulkan hardware anisotropic sampler from the GPU compute rasterizer. Analytic perspective-correct derivatives are supplied through `textureGrad`; the texture unit chooses its footprint and mip level. Wrapping remains seamless; clamped-edge footprints, GS region/cropped textures, render-target arrays and framebuffer-feedback sampling keep the original path. No CPU texture filtering is added. Levels are clamped to the GPU's `maxSamplerAnisotropy`; devices without the feature use bilinear sampling. It defaults to off and is passed as `REO_TEXTURE_ANISOTROPY=1|2|4|8|16`.

The native CMake target compiles and validates four enhanced shader variants and embeds them in the renderer library. It extends the original precomputed resource layouts with sampler binding 23 because the pinned Granite build has runtime SPIRV-Cross reflection disabled. Off and passes without eligible draws use the original embedded shaders, avoiding extra shader register pressure for menus/backgrounds. `resident_gs/shaders/BuildAnisotropic.cmake` injects the enhancement into the pinned upstream shader and fails if the expected integration points disappear.
