#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017B960
// Address: 0x17b960 - 0x17ba20
void sub_0017B960_0x17b960(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017B960_0x17b960");
#endif

    switch (ctx->pc) {
        case 0x17b9ccu: goto label_17b9cc;
        case 0x17ba00u: goto label_17ba00;
        default: break;
    }

    ctx->pc = 0x17b960u;

    // 0x17b960: 0x27bdffa0  addiu       $sp, $sp, -0x60
    ctx->pc = 0x17b960u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967200));
    // 0x17b964: 0xffb00030  sd          $s0, 0x30($sp)
    ctx->pc = 0x17b964u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 16));
    // 0x17b968: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x17b968u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17b96c: 0xffb10038  sd          $s1, 0x38($sp)
    ctx->pc = 0x17b96cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 17));
    // 0x17b970: 0x26110004  addiu       $s1, $s0, 0x4
    ctx->pc = 0x17b970u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 16), 4));
    // 0x17b974: 0xffb20040  sd          $s2, 0x40($sp)
    ctx->pc = 0x17b974u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 18));
    // 0x17b978: 0x27b20010  addiu       $s2, $sp, 0x10
    ctx->pc = 0x17b978u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x17b97c: 0xffb30048  sd          $s3, 0x48($sp)
    ctx->pc = 0x17b97cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 19));
    // 0x17b980: 0xc0982d  daddu       $s3, $a2, $zero
    ctx->pc = 0x17b980u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17b984: 0xffb40050  sd          $s4, 0x50($sp)
    ctx->pc = 0x17b984u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 20));
    // 0x17b988: 0x80a02d  daddu       $s4, $a0, $zero
    ctx->pc = 0x17b988u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17b98c: 0xffbf0058  sd          $ra, 0x58($sp)
    ctx->pc = 0x17b98cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 88), GPR_U64(ctx, 31));
    // 0x17b990: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x17b990u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17b994: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x17b994u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17b998: 0x8e030048  lw          $v1, 0x48($s0)
    ctx->pc = 0x17b998u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 72)));
    // 0x17b99c: 0x8e070044  lw          $a3, 0x44($s0)
    ctx->pc = 0x17b99cu;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 68)));
    // 0x17b9a0: 0x317c2  srl         $v0, $v1, 31
    ctx->pc = 0x17b9a0u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 3), 31));
    // 0x17b9a4: 0x8e260000  lw          $a2, 0x0($s1)
    ctx->pc = 0x17b9a4u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x17b9a8: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x17b9a8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x17b9ac: 0xafa70014  sw          $a3, 0x14($sp)
    ctx->pc = 0x17b9acu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 7));
    // 0x17b9b0: 0x21043  sra         $v0, $v0, 1
    ctx->pc = 0x17b9b0u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 1));
    // 0x17b9b4: 0xafa60000  sw          $a2, 0x0($sp)
    ctx->pc = 0x17b9b4u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 6));
    // 0x17b9b8: 0xafa20018  sw          $v0, 0x18($sp)
    ctx->pc = 0x17b9b8u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 2));
    // 0x17b9bc: 0xafa70004  sw          $a3, 0x4($sp)
    ctx->pc = 0x17b9bcu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 4), GPR_U32(ctx, 7));
    // 0x17b9c0: 0xafa30008  sw          $v1, 0x8($sp)
    ctx->pc = 0x17b9c0u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 3));
    // 0x17b9c4: 0xc053dac  jal         func_14F6B0
    ctx->pc = 0x17B9C4u;
    SET_GPR_U32(ctx, 31, 0x17B9CCu);
    ctx->pc = 0x17B9C8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17B9C4u;
            // 0x17b9c8: 0xafb30010  sw          $s3, 0x10($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 19));
        ctx->in_delay_slot = false;
    ctx->pc = 0x14F6B0u;
    if (runtime->hasFunction(0x14F6B0u)) {
        auto targetFn = runtime->lookupFunction(0x14F6B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17B9CCu; }
        if (ctx->pc != 0x17B9CCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0014F6B0_0x14f6b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17B9CCu; }
        if (ctx->pc != 0x17B9CCu) { return; }
    }
    ctx->pc = 0x17B9CCu;
label_17b9cc:
    // 0x17b9cc: 0x8e070048  lw          $a3, 0x48($s0)
    ctx->pc = 0x17b9ccu;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 72)));
    // 0x17b9d0: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x17b9d0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17b9d4: 0x8e020044  lw          $v0, 0x44($s0)
    ctx->pc = 0x17b9d4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 68)));
    // 0x17b9d8: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x17b9d8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17b9dc: 0x8e230000  lw          $v1, 0x0($s1)
    ctx->pc = 0x17b9dcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x17b9e0: 0x8e86003c  lw          $a2, 0x3C($s4)
    ctx->pc = 0x17b9e0u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 60)));
    // 0x17b9e4: 0xafb30010  sw          $s3, 0x10($sp)
    ctx->pc = 0x17b9e4u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 19));
    // 0x17b9e8: 0xafa30000  sw          $v1, 0x0($sp)
    ctx->pc = 0x17b9e8u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 3));
    // 0x17b9ec: 0xafa20014  sw          $v0, 0x14($sp)
    ctx->pc = 0x17b9ecu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 2));
    // 0x17b9f0: 0xafa70018  sw          $a3, 0x18($sp)
    ctx->pc = 0x17b9f0u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 7));
    // 0x17b9f4: 0xafa20004  sw          $v0, 0x4($sp)
    ctx->pc = 0x17b9f4u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 4), GPR_U32(ctx, 2));
    // 0x17b9f8: 0xc054044  jal         func_150110
    ctx->pc = 0x17B9F8u;
    SET_GPR_U32(ctx, 31, 0x17BA00u);
    ctx->pc = 0x17B9FCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17B9F8u;
            // 0x17b9fc: 0xafa70008  sw          $a3, 0x8($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 7));
        ctx->in_delay_slot = false;
    ctx->pc = 0x150110u;
    if (runtime->hasFunction(0x150110u)) {
        auto targetFn = runtime->lookupFunction(0x150110u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17BA00u; }
        if (ctx->pc != 0x17BA00u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00150110_0x150110(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17BA00u; }
        if (ctx->pc != 0x17BA00u) { return; }
    }
    ctx->pc = 0x17BA00u;
label_17ba00:
    // 0x17ba00: 0xdfb00030  ld          $s0, 0x30($sp)
    ctx->pc = 0x17ba00u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x17ba04: 0xdfb10038  ld          $s1, 0x38($sp)
    ctx->pc = 0x17ba04u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x17ba08: 0xdfb20040  ld          $s2, 0x40($sp)
    ctx->pc = 0x17ba08u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x17ba0c: 0xdfb30048  ld          $s3, 0x48($sp)
    ctx->pc = 0x17ba0cu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x17ba10: 0xdfb40050  ld          $s4, 0x50($sp)
    ctx->pc = 0x17ba10u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x17ba14: 0xdfbf0058  ld          $ra, 0x58($sp)
    ctx->pc = 0x17ba14u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 88)));
    // 0x17ba18: 0x3e00008  jr          $ra
    ctx->pc = 0x17BA18u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17BA1Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17BA18u;
            // 0x17ba1c: 0x27bd0060  addiu       $sp, $sp, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17B9CCu: goto label_17b9cc;
            case 0x17BA00u: goto label_17ba00;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17BA20u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
