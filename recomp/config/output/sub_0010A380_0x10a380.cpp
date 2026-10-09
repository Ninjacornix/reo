#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0010A380
// Address: 0x10a380 - 0x10a448
void sub_0010A380_0x10a380(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0010A380_0x10a380");
#endif

    switch (ctx->pc) {
        case 0x10a434u: goto label_10a434;
        default: break;
    }

    ctx->pc = 0x10a380u;

    // 0x10a380: 0x44066000  mfc1        $a2, $f12
    ctx->pc = 0x10a380u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[12], sizeof(bits)); SET_GPR_U32(ctx, 6, bits); }
    // 0x10a384: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x10a384u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x10a388: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x10a388u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x10a38c: 0xe7b40008  swc1        $f20, 0x8($sp)
    ctx->pc = 0x10a38cu;
    { float f = ctx->f[20]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 8), bits); }
    // 0x10a390: 0x3c027fff  lui         $v0, 0x7FFF
    ctx->pc = 0x10a390u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32767 << 16));
    // 0x10a394: 0x3442ffff  ori         $v0, $v0, 0xFFFF
    ctx->pc = 0x10a394u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65535);
    // 0x10a398: 0x3c03007f  lui         $v1, 0x7F
    ctx->pc = 0x10a398u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)127 << 16));
    // 0x10a39c: 0xc21024  and         $v0, $a2, $v0
    ctx->pc = 0x10a39cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 6) & GPR_U64(ctx, 2));
    // 0x10a3a0: 0x3463ffff  ori         $v1, $v1, 0xFFFF
    ctx->pc = 0x10a3a0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)65535);
    // 0x10a3a4: 0x22dc2  srl         $a1, $v0, 23
    ctx->pc = 0x10a3a4u;
    SET_GPR_S32(ctx, 5, (int32_t)SRL32(GPR_U32(ctx, 2), 23));
    // 0x10a3a8: 0x62182b  sltu        $v1, $v1, $v0
    ctx->pc = 0x10a3a8u;
    SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x10a3ac: 0x46006006  mov.s       $f0, $f12
    ctx->pc = 0x10a3acu;
    ctx->f[0] = FPU_MOV_S(ctx->f[12]);
    // 0x10a3b0: 0x10600021  beqz        $v1, . + 4 + (0x21 << 2)
    ctx->pc = 0x10A3B0u;
    {
        const bool branch_taken_0x10a3b0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x10A3B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10A3B0u;
            // 0x10a3b4: 0xa42821  addu        $a1, $a1, $a0 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 4)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10a3b0) {
            ctx->pc = 0x10A438u;
            goto label_10a438;
        }
    }
    ctx->pc = 0x10A3B8u;
    // 0x10a3b8: 0x28a20100  slti        $v0, $a1, 0x100
    ctx->pc = 0x10a3b8u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)256) ? 1 : 0);
    // 0x10a3bc: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x10A3BCu;
    {
        const bool branch_taken_0x10a3bc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x10A3C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10A3BCu;
            // 0x10a3c0: 0x46006346  mov.s       $f13, $f12 (Delay Slot)
        ctx->f[13] = FPU_MOV_S(ctx->f[12]);
        ctx->in_delay_slot = false;
        if (branch_taken_0x10a3bc) {
            ctx->pc = 0x10A3D8u;
            goto label_10a3d8;
        }
    }
    ctx->pc = 0x10A3C4u;
    // 0x10a3c4: 0x3c017149  lui         $at, 0x7149
    ctx->pc = 0x10a3c4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)29001 << 16));
    // 0x10a3c8: 0x3421f2c9  ori         $at, $at, 0xF2C9
    ctx->pc = 0x10a3c8u;
    SET_GPR_U64(ctx, 1, GPR_U64(ctx, 1) | (uint64_t)(uint16_t)62153);
    // 0x10a3cc: 0x4481a000  mtc1        $at, $f20
    ctx->pc = 0x10a3ccu;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[20], &bits, sizeof(bits)); }
    // 0x10a3d0: 0x10000016  b           . + 4 + (0x16 << 2)
    ctx->pc = 0x10A3D0u;
    {
        const bool branch_taken_0x10a3d0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x10a3d0) {
            ctx->pc = 0x10A42Cu;
            goto label_10a42c;
        }
    }
    ctx->pc = 0x10A3D8u;
label_10a3d8:
    // 0x10a3d8: 0x18a00009  blez        $a1, . + 4 + (0x9 << 2)
    ctx->pc = 0x10A3D8u;
    {
        const bool branch_taken_0x10a3d8 = (GPR_S64(ctx, 5) <= 0);
        ctx->pc = 0x10A3DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10A3D8u;
            // 0x10a3dc: 0x3402c350  ori         $v0, $zero, 0xC350 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)50000);
        ctx->in_delay_slot = false;
        if (branch_taken_0x10a3d8) {
            ctx->pc = 0x10A400u;
            goto label_10a400;
        }
    }
    ctx->pc = 0x10A3E0u;
    // 0x10a3e0: 0x3c02807f  lui         $v0, 0x807F
    ctx->pc = 0x10a3e0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32895 << 16));
    // 0x10a3e4: 0x51dc0  sll         $v1, $a1, 23
    ctx->pc = 0x10a3e4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 5), 23));
    // 0x10a3e8: 0x3442ffff  ori         $v0, $v0, 0xFFFF
    ctx->pc = 0x10a3e8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65535);
    // 0x10a3ec: 0xc21024  and         $v0, $a2, $v0
    ctx->pc = 0x10a3ecu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 6) & GPR_U64(ctx, 2));
    // 0x10a3f0: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x10a3f0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x10a3f4: 0x44826000  mtc1        $v0, $f12
    ctx->pc = 0x10a3f4u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[12], &bits, sizeof(bits)); }
    // 0x10a3f8: 0x1000000f  b           . + 4 + (0xF << 2)
    ctx->pc = 0x10A3F8u;
    {
        const bool branch_taken_0x10a3f8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10A3FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10A3F8u;
            // 0x10a3fc: 0x46006006  mov.s       $f0, $f12 (Delay Slot)
        ctx->f[0] = FPU_MOV_S(ctx->f[12]);
        ctx->in_delay_slot = false;
        if (branch_taken_0x10a3f8) {
            ctx->pc = 0x10A438u;
            goto label_10a438;
        }
    }
    ctx->pc = 0x10A400u;
label_10a400:
    // 0x10a400: 0x44102a  slt         $v0, $v0, $a0
    ctx->pc = 0x10a400u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 4)) ? 1 : 0);
    // 0x10a404: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x10A404u;
    {
        const bool branch_taken_0x10a404 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x10A408u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10A404u;
            // 0x10a408: 0x46006346  mov.s       $f13, $f12 (Delay Slot)
        ctx->f[13] = FPU_MOV_S(ctx->f[12]);
        ctx->in_delay_slot = false;
        if (branch_taken_0x10a404) {
            ctx->pc = 0x10A420u;
            goto label_10a420;
        }
    }
    ctx->pc = 0x10A40Cu;
    // 0x10a40c: 0x3c017149  lui         $at, 0x7149
    ctx->pc = 0x10a40cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)29001 << 16));
    // 0x10a410: 0x3421f2c9  ori         $at, $at, 0xF2C9
    ctx->pc = 0x10a410u;
    SET_GPR_U64(ctx, 1, GPR_U64(ctx, 1) | (uint64_t)(uint16_t)62153);
    // 0x10a414: 0x4481a000  mtc1        $at, $f20
    ctx->pc = 0x10a414u;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[20], &bits, sizeof(bits)); }
    // 0x10a418: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x10A418u;
    {
        const bool branch_taken_0x10a418 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x10a418) {
            ctx->pc = 0x10A42Cu;
            goto label_10a42c;
        }
    }
    ctx->pc = 0x10A420u;
label_10a420:
    // 0x10a420: 0x3c010da2  lui         $at, 0xDA2
    ctx->pc = 0x10a420u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)3490 << 16));
    // 0x10a424: 0x3421425f  ori         $at, $at, 0x425F
    ctx->pc = 0x10a424u;
    SET_GPR_U64(ctx, 1, GPR_U64(ctx, 1) | (uint64_t)(uint16_t)16991);
    // 0x10a428: 0x4481a000  mtc1        $at, $f20
    ctx->pc = 0x10a428u;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[20], &bits, sizeof(bits)); }
label_10a42c:
    // 0x10a42c: 0xc0428ac  jal         func_10A2B0
    ctx->pc = 0x10A42Cu;
    SET_GPR_U32(ctx, 31, 0x10A434u);
    ctx->pc = 0x10A430u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10A42Cu;
            // 0x10a430: 0x4600a306  mov.s       $f12, $f20 (Delay Slot)
        ctx->f[12] = FPU_MOV_S(ctx->f[20]);
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A2B0u;
    if (runtime->hasFunction(0x10A2B0u)) {
        auto targetFn = runtime->lookupFunction(0x10A2B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10A434u; }
        if (ctx->pc != 0x10A434u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A2B0_0x10a2b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10A434u; }
        if (ctx->pc != 0x10A434u) { return; }
    }
    ctx->pc = 0x10A434u;
label_10a434:
    // 0x10a434: 0x46140002  mul.s       $f0, $f0, $f20
    ctx->pc = 0x10a434u;
    ctx->f[0] = FPU_MUL_S(ctx->f[0], ctx->f[20]);
label_10a438:
    // 0x10a438: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x10a438u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x10a43c: 0xc7b40008  lwc1        $f20, 0x8($sp)
    ctx->pc = 0x10a43cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 8)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[20] = f; }
    // 0x10a440: 0x3e00008  jr          $ra
    ctx->pc = 0x10A440u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x10A444u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10A440u;
            // 0x10a444: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x10A3D8u: goto label_10a3d8;
            case 0x10A400u: goto label_10a400;
            case 0x10A420u: goto label_10a420;
            case 0x10A42Cu: goto label_10a42c;
            case 0x10A434u: goto label_10a434;
            case 0x10A438u: goto label_10a438;
            default: break;
        }
        return;
    }
    ctx->pc = 0x10A448u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
