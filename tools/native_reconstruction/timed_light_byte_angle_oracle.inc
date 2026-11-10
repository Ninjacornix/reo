// Test-only370080 entry extracted from output_overlay/sub_00370000.
// Every word including formerly uncommented delay slots is checked against owned o0.
void oracle_370080(std::uint8_t* rdram,R5900Context* ctx,PS2Runtime* runtime){
    // 0x370080: 0x308200ff
    ctx->pc = 0x370080u;
    SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 4), 255));
    // 0x370084: 0x4400004
    ctx->pc = 0x370084u;
    {
        const bool branch_taken_0x370084 = (GPR_S32(ctx, 2) < 0);
    // 0x370088: 0x00021842 (delay-slot word, supplied from owned o0)
        ctx->pc = 0x370088u;
        SET_GPR_U32(ctx, 3, SRL32(GPR_U32(ctx, 2), 1));
        if (branch_taken_0x370084) {
            ctx->pc = 0x370098u;
            goto label_370098;
        }
    }
    ctx->pc = 0x37008Cu;
    // 0x37008c: 0x44820000
    ctx->pc = 0x37008cu;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x370090: 0x10000007
    ctx->pc = 0x370090u;
    {
        const bool branch_taken_0x370090 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
    // 0x370094: 0x46800060 (delay-slot word, supplied from owned o0)
        ctx->pc = 0x370094u;
        { int32_t tmp; std::memcpy(&tmp, &ctx->f[0], sizeof(tmp)); ctx->f[1] = FPU_CVT_S_W(tmp); }
        if (branch_taken_0x370090) {
            ctx->pc = 0x3700B0u;
            goto label_3700b0;
        }
    }
    ctx->pc = 0x370098u;
label_370098:
    // 0x370098: 0x30420001
    ctx->pc = 0x370098u;
    SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 2), 1));
    // 0x37009c: 0x621825
    ctx->pc = 0x37009cu;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x3700a0: 0x44830000
    ctx->pc = 0x3700a0u;
    { uint32_t bits = GPR_U32(ctx, 3); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x3700a4: 0x0
    ctx->pc = 0x3700a4u;
    // NOP
    // 0x3700a8: 0x46800060
    ctx->pc = 0x3700a8u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[0], sizeof(tmp)); ctx->f[1] = FPU_CVT_S_W(tmp); }
    // 0x3700ac: 0x46010840
    ctx->pc = 0x3700acu;
    ctx->f[1] = FPU_ADD_S(ctx->f[1], ctx->f[1]);
label_3700b0:
    // 0x3700b0: 0x3c010039
    ctx->pc = 0x3700b0u;
    SET_GPR_U32(ctx, 1, ((uint32_t)57 << 16));
    // 0x3700b4: 0xc420b298
    ctx->pc = 0x3700b4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294947480)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x3700b8: 0x8064864
    ctx->pc = 0x3700B8u;
    // 0x3700bc: 0x46010302 (delay-slot word, supplied from owned o0)
    ctx->pc = 0x3700BCu;
    ctx->f[12] = FPU_MUL_S(ctx->f[0], ctx->f[1]);
    ctx->pc = 0x192190u;
    {
        auto targetFn = runtime->lookupFunction(0x192190u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        return;
    }
}
