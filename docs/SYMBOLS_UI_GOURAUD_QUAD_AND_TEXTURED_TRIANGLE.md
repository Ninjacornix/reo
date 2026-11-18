# Resident gouraud rectangle and textured triangle packets

Static owned resident executable SHA-256 `06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46`. Both complete original bodies and full0x30-byte copied templates reviewed. Values hexadecimal. No target execution or rendering test.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [0x1ABDF0](../recomp/config/output/sub_001ABDF0_0x1abdf0.cpp) | `emit_four_color_screen_rectangle_as_gouraud_triangle_strip` | Confirmed complete packet/descriptor/control flow | Global29FDA4 nonzero returns1. Copies3quadwordtemplate233F90 toscratch70000000. Signedhalf descriptor0/2/4/6 aretwoXYendpoints;Xscales width29F9BC/640 then16,Ytimes16 halvedwhen29F9B4==0;addscenter(4096-dimension)/2*16. Fourcolors8/C/10/14 each198B60(...,1),RGB byte repacking plus upperbit32. Stripvertices(left,top),(right,top),(left,bottom),(right,bottom). Zfromfloat29F9F4 throughunsignedconversionbranch.193E20(scratch),returns1;no clipping/framewait orGPUcompletion. |
| [0x1AC240](../recomp/config/output/sub_001AC240_0x1ac240.cpp) | `emit_textured_screen_triangle_with_three_uv_pairs_and_single_color` | Confirmed complete packet/descriptor/control flow | Same disableguard/center/Xscale/Yfieldmode conversion,three signedXYpairs0..A. Copies3quadwordtemplate234000;wordCcolor198B60(...,0),RGBAQbit32. Three signedUVpairs10/12,14/16,18/1A become(component<<4)+8;writesUV/XYZ2 pervertexwithsharedfloatdepth29F9F4.193E20,returns1;no texturelookup/binding locally. |

Owned233F90..233FC0 SHA-256 `6dd1a912419cd8883142ce1d6bd9fbf3ba4c5471c1df85c0091c6c93ce5fd0f7`: six64-bitwords [70000006,0,9400000000008001,515151510,4C,0]. DMAENDQWC6,GIFREGLISTNREG9,PRIM thenRGBAQ/XYZ2 repeatedfourvertices;PRIM4C triangle strip/IIP/alpha blend. Owned234000..234030 SHA-256 `ecd5df4526e0d50c2057da0a0addc4478182b786a6d4135b97914785934d09d4`: [70000005,0,8400000000008001,53535310,153,0],DMAENDQWC5,REGLISTNREG8,PRIM/RGBAQ thenUV/XYZ2 threetimes;PRIM153 triangle/texture/alpha blend/FST. Ownedbytes corroborate geometry roles independently of proximity.

Related [rectangle/glyph packets](SYMBOLS_UI_RECTANGLE_GLYPH_PACKETS.md),same sharedscratch and193E20 submission. Neither body allocates geometry resources or changes the game clock. Float out-of-range/NaN conversion remains guest instruction semantics. No measured cost or batching fix is claimed.

Audit: 2 rows, 520 verified owned instruction words; 5 omitted interval words are zero/NOP; 0 omitted nonzero words.
