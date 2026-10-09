#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017C420
// Address: 0x17c420 - 0x17c530
void sub_0017C420_0x17c420(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017C420_0x17c420");
#endif

    switch (ctx->pc) {
        case 0x17c4a8u: goto label_17c4a8;
        case 0x17c4f8u: goto label_17c4f8;
        case 0x17c508u: goto label_17c508;
        default: break;
    }

    ctx->pc = 0x17c420u;

    // 0x17c420: 0x27bdff80  addiu       $sp, $sp, -0x80
    ctx->pc = 0x17c420u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967168));
    // 0x17c424: 0x240a0040  addiu       $t2, $zero, 0x40
    ctx->pc = 0x17c424u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 0), 64));
    // 0x17c428: 0xffb00040  sd          $s0, 0x40($sp)
    ctx->pc = 0x17c428u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 16));
    // 0x17c42c: 0xffb10048  sd          $s1, 0x48($sp)
    ctx->pc = 0x17c42cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 17));
    // 0x17c430: 0xc0882d  daddu       $s1, $a2, $zero
    ctx->pc = 0x17c430u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17c434: 0xffb20050  sd          $s2, 0x50($sp)
    ctx->pc = 0x17c434u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 18));
    // 0x17c438: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x17c438u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17c43c: 0xffb30058  sd          $s3, 0x58($sp)
    ctx->pc = 0x17c43cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 88), GPR_U64(ctx, 19));
    // 0x17c440: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x17c440u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17c444: 0xffb40060  sd          $s4, 0x60($sp)
    ctx->pc = 0x17c444u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 20));
    // 0x17c448: 0xe0a02d  daddu       $s4, $a3, $zero
    ctx->pc = 0x17c448u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17c44c: 0xffb50068  sd          $s5, 0x68($sp)
    ctx->pc = 0x17c44cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 104), GPR_U64(ctx, 21));
    // 0x17c450: 0xffb60070  sd          $s6, 0x70($sp)
    ctx->pc = 0x17c450u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 112), GPR_U64(ctx, 22));
    // 0x17c454: 0xa0b02d  daddu       $s6, $a1, $zero
    ctx->pc = 0x17c454u;
    SET_GPR_U64(ctx, 22, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17c458: 0xffbf0078  sd          $ra, 0x78($sp)
    ctx->pc = 0x17c458u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 120), GPR_U64(ctx, 31));
    // 0x17c45c: 0x26d00004  addiu       $s0, $s6, 0x4
    ctx->pc = 0x17c45cu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 22), 4));
    // 0x17c460: 0x8e030008  lw          $v1, 0x8($s0)
    ctx->pc = 0x17c460u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x17c464: 0x8e090004  lw          $t1, 0x4($s0)
    ctx->pc = 0x17c464u;
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x17c468: 0x8e480008  lw          $t0, 0x8($s2)
    ctx->pc = 0x17c468u;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 8)));
    // 0x17c46c: 0x317c2  srl         $v0, $v1, 31
    ctx->pc = 0x17c46cu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 3), 31));
    // 0x17c470: 0x8e46000c  lw          $a2, 0xC($s2)
    ctx->pc = 0x17c470u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 12)));
    // 0x17c474: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x17c474u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x17c478: 0x8e050000  lw          $a1, 0x0($s0)
    ctx->pc = 0x17c478u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x17c47c: 0x120a82d  daddu       $s5, $t1, $zero
    ctx->pc = 0x17c47cu;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 9) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17c480: 0x108a80b  movn        $s5, $t0, $t0
    ctx->pc = 0x17c480u;
    if (GPR_U64(ctx, 8) != 0) SET_GPR_VEC(ctx, 21, GPR_VEC(ctx, 8));
    // 0x17c484: 0xafaa000c  sw          $t2, 0xC($sp)
    ctx->pc = 0x17c484u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 12), GPR_U32(ctx, 10));
    // 0x17c488: 0xafa50000  sw          $a1, 0x0($sp)
    ctx->pc = 0x17c488u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 5));
    // 0x17c48c: 0x29843  sra         $s3, $v0, 1
    ctx->pc = 0x17c48cu;
    SET_GPR_S32(ctx, 19, SRA32(GPR_S32(ctx, 2), 1));
    // 0x17c490: 0xafa90004  sw          $t1, 0x4($sp)
    ctx->pc = 0x17c490u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 4), GPR_U32(ctx, 9));
    // 0x17c494: 0x10c00002  beqz        $a2, . + 4 + (0x2 << 2)
    ctx->pc = 0x17C494u;
    {
        const bool branch_taken_0x17c494 = (GPR_U64(ctx, 6) == GPR_U64(ctx, 0));
        ctx->pc = 0x17C498u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17C494u;
            // 0x17c498: 0xafa30008  sw          $v1, 0x8($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17c494) {
            ctx->pc = 0x17C4A0u;
            goto label_17c4a0;
        }
    }
    ctx->pc = 0x17C49Cu;
    // 0x17c49c: 0xc0982d  daddu       $s3, $a2, $zero
    ctx->pc = 0x17c49cu;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
label_17c4a0:
    // 0x17c4a0: 0xc05f14c  jal         func_17C530
    ctx->pc = 0x17C4A0u;
    SET_GPR_U32(ctx, 31, 0x17C4A8u);
    ctx->pc = 0x17C530u;
    if (runtime->hasFunction(0x17C530u)) {
        auto targetFn = runtime->lookupFunction(0x17C530u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17C4A8u; }
        if (ctx->pc != 0x17C4A8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017C530_0x17c530(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17C4A8u; }
        if (ctx->pc != 0x17C4A8u) { return; }
    }
    ctx->pc = 0x17C4A8u;
label_17c4a8:
    // 0x17c4a8: 0x24060020  addiu       $a2, $zero, 0x20
    ctx->pc = 0x17c4a8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
    // 0x17c4ac: 0x8e030008  lw          $v1, 0x8($s0)
    ctx->pc = 0x17c4acu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x17c4b0: 0x24050010  addiu       $a1, $zero, 0x10
    ctx->pc = 0x17c4b0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x17c4b4: 0xafa20020  sw          $v0, 0x20($sp)
    ctx->pc = 0x17c4b4u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 2));
    // 0x17c4b8: 0x317c2  srl         $v0, $v1, 31
    ctx->pc = 0x17c4b8u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 3), 31));
    // 0x17c4bc: 0x8e040004  lw          $a0, 0x4($s0)
    ctx->pc = 0x17c4bcu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x17c4c0: 0x621821  addu        $v1, $v1, $v0
    ctx->pc = 0x17c4c0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x17c4c4: 0xafb40024  sw          $s4, 0x24($sp)
    ctx->pc = 0x17c4c4u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 36), GPR_U32(ctx, 20));
    // 0x17c4c8: 0x31843  sra         $v1, $v1, 1
    ctx->pc = 0x17c4c8u;
    SET_GPR_S32(ctx, 3, SRA32(GPR_S32(ctx, 3), 1));
    // 0x17c4cc: 0xafa40030  sw          $a0, 0x30($sp)
    ctx->pc = 0x17c4ccu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 48), GPR_U32(ctx, 4));
    // 0x17c4d0: 0xafb50028  sw          $s5, 0x28($sp)
    ctx->pc = 0x17c4d0u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 40), GPR_U32(ctx, 21));
    // 0x17c4d4: 0xafb3002c  sw          $s3, 0x2C($sp)
    ctx->pc = 0x17c4d4u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 44), GPR_U32(ctx, 19));
    // 0x17c4d8: 0x1225000b  beq         $s1, $a1, . + 4 + (0xB << 2)
    ctx->pc = 0x17C4D8u;
    {
        const bool branch_taken_0x17c4d8 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 5));
        ctx->pc = 0x17C4DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17C4D8u;
            // 0x17c4dc: 0xafa30034  sw          $v1, 0x34($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 52), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17c4d8) {
            ctx->pc = 0x17C508u;
            goto label_17c508;
        }
    }
    ctx->pc = 0x17C4E0u;
    // 0x17c4e0: 0x5626000a  bnel        $s1, $a2, . + 4 + (0xA << 2)
    ctx->pc = 0x17C4E0u;
    {
        const bool branch_taken_0x17c4e0 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 6));
        if (branch_taken_0x17c4e0) {
            ctx->pc = 0x17C4E4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x17C4E0u;
            // 0x17c4e4: 0xdfb00040  ld          $s0, 0x40($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 64)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x17C50Cu;
            goto label_17c50c;
        }
    }
    ctx->pc = 0x17C4E8u;
    // 0x17c4e8: 0x2c0282d  daddu       $a1, $s6, $zero
    ctx->pc = 0x17c4e8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17c4ec: 0x2406000d  addiu       $a2, $zero, 0xD
    ctx->pc = 0x17c4ecu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 13));
    // 0x17c4f0: 0xc05f164  jal         func_17C590
    ctx->pc = 0x17C4F0u;
    SET_GPR_U32(ctx, 31, 0x17C4F8u);
    ctx->pc = 0x17C4F4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17C4F0u;
            // 0x17c4f4: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17C590u;
    if (runtime->hasFunction(0x17C590u)) {
        auto targetFn = runtime->lookupFunction(0x17C590u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17C4F8u; }
        if (ctx->pc != 0x17C4F8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017C590_0x17c590(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17C4F8u; }
        if (ctx->pc != 0x17C4F8u) { return; }
    }
    ctx->pc = 0x17C4F8u;
label_17c4f8:
    // 0x17c4f8: 0x8e46003c  lw          $a2, 0x3C($s2)
    ctx->pc = 0x17c4f8u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 60)));
    // 0x17c4fc: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x17c4fcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17c500: 0xc0524b6  jal         func_1492D8
    ctx->pc = 0x17C500u;
    SET_GPR_U32(ctx, 31, 0x17C508u);
    ctx->pc = 0x17C504u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17C500u;
            // 0x17c504: 0x27a50020  addiu       $a1, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1492D8u;
    if (runtime->hasFunction(0x1492D8u)) {
        auto targetFn = runtime->lookupFunction(0x1492D8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17C508u; }
        if (ctx->pc != 0x17C508u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001492D8_0x1492d8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17C508u; }
        if (ctx->pc != 0x17C508u) { return; }
    }
    ctx->pc = 0x17C508u;
label_17c508:
    // 0x17c508: 0xdfb00040  ld          $s0, 0x40($sp)
    ctx->pc = 0x17c508u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 64)));
label_17c50c:
    // 0x17c50c: 0xdfb10048  ld          $s1, 0x48($sp)
    ctx->pc = 0x17c50cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x17c510: 0xdfb20050  ld          $s2, 0x50($sp)
    ctx->pc = 0x17c510u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x17c514: 0xdfb30058  ld          $s3, 0x58($sp)
    ctx->pc = 0x17c514u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 88)));
    // 0x17c518: 0xdfb40060  ld          $s4, 0x60($sp)
    ctx->pc = 0x17c518u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x17c51c: 0xdfb50068  ld          $s5, 0x68($sp)
    ctx->pc = 0x17c51cu;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 104)));
    // 0x17c520: 0xdfb60070  ld          $s6, 0x70($sp)
    ctx->pc = 0x17c520u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x17c524: 0xdfbf0078  ld          $ra, 0x78($sp)
    ctx->pc = 0x17c524u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 120)));
    // 0x17c528: 0x3e00008  jr          $ra
    ctx->pc = 0x17C528u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17C52Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17C528u;
            // 0x17c52c: 0x27bd0080  addiu       $sp, $sp, 0x80 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 128));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17C4A0u: goto label_17c4a0;
            case 0x17C4A8u: goto label_17c4a8;
            case 0x17C4F8u: goto label_17c4f8;
            case 0x17C508u: goto label_17c508;
            case 0x17C50Cu: goto label_17c50c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17C530u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
