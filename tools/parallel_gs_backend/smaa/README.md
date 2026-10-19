# SMAA presentation

SMAA 1x, High preset, using the unmodified upstream shader and lookup headers pinned in [upstream/SOURCE.json](upstream/SOURCE.json). Their MIT notices are retained; see [upstream/LICENSE.txt](upstream/LICENSE.txt).

The existing fullscreen shader first scales the completed GS image into an output-sized RGBA8 texture. Three GPU passes detect luma edges, calculate RGBA8 blend weights, and blend neighbouring pixels into the shared DXGI presentation target. Edge and weight attachments are cleared every frame. Lookup tables use RG8 and R8 UNORM with linear-clamp sampling. Brightness/gamma is applied once in the final pass; letterbox bars stay black.

All passes use the existing Vulkan device and graphics queue with explicit attachment-to-sampled-image barriers. Intermediate images are reused and recreated after the presenter's resize fence. No temporal history, second device, gameplay timing change or normal-path readback is introduced.

Set `REO_POST_AA=smaa`, or choose SMAA in the launcher. The three `present_smaa_*.frag.spv` modules must be deployed beside the other presentation modules. Off and FXAA retain their original paths. This does not increase the game's internal rendering resolution.
