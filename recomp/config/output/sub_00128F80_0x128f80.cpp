#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00128F80
// Address: 0x128f80 - 0x129010
void sub_00128F80_0x128f80(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00128F80_0x128f80");
#endif

    switch (ctx->pc) {
        case 0x128f94u: goto label_128f94;
        case 0x128facu: goto label_128fac;
        case 0x128fc8u: goto label_128fc8;
        default: break;
    }

    ctx->pc = 0x128f80u;

    // 0x128f80: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x128f80u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x128f84: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x128f84u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x128f88: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x128f88u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x128f8c: 0xc04a3ca  jal         func_128F28
    ctx->pc = 0x128F8Cu;
    SET_GPR_U32(ctx, 31, 0x128F94u);
    ctx->pc = 0x128F28u;
    if (runtime->hasFunction(0x128F28u)) {
        auto targetFn = runtime->lookupFunction(0x128F28u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x128F94u; }
        if (ctx->pc != 0x128F94u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00128F28_0x128f28(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x128F94u; }
        if (ctx->pc != 0x128F94u) { return; }
    }
    ctx->pc = 0x128F94u;
label_128f94:
    // 0x128f94: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x128f94u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x128f98: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x128f98u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x128f9c: 0x12000017  beqz        $s0, . + 4 + (0x17 << 2)
    ctx->pc = 0x128F9Cu;
    {
        const bool branch_taken_0x128f9c = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        ctx->pc = 0x128FA0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x128F9Cu;
            // 0x128fa0: 0x24050100  addiu       $a1, $zero, 0x100 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 256));
        ctx->in_delay_slot = false;
        if (branch_taken_0x128f9c) {
            ctx->pc = 0x128FFCu;
            goto label_128ffc;
        }
    }
    ctx->pc = 0x128FA4u;
    // 0x128fa4: 0xc04c0f6  jal         func_1303D8
    ctx->pc = 0x128FA4u;
    SET_GPR_U32(ctx, 31, 0x128FACu);
    ctx->pc = 0x1303D8u;
    if (runtime->hasFunction(0x1303D8u)) {
        auto targetFn = runtime->lookupFunction(0x1303D8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x128FACu; }
        if (ctx->pc != 0x128FACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001303D8_0x1303d8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x128FACu; }
        if (ctx->pc != 0x128FACu) { return; }
    }
    ctx->pc = 0x128FACu;
label_128fac:
    // 0x128fac: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x128facu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x128fb0: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x128fb0u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x128fb4: 0xae020004  sw          $v0, 0x4($s0)
    ctx->pc = 0x128fb4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 2));
    // 0x128fb8: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x128FB8u;
    {
        const bool branch_taken_0x128fb8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x128FBCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x128FB8u;
            // 0x128fbc: 0x24849e80  addiu       $a0, $a0, -0x6180 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294942336));
        ctx->in_delay_slot = false;
        if (branch_taken_0x128fb8) {
            ctx->pc = 0x128FD0u;
            goto label_128fd0;
        }
    }
    ctx->pc = 0x128FC0u;
    // 0x128fc0: 0xc04a034  jal         func_1280D0
    ctx->pc = 0x128FC0u;
    SET_GPR_U32(ctx, 31, 0x128FC8u);
    ctx->pc = 0x1280D0u;
    if (runtime->hasFunction(0x1280D0u)) {
        auto targetFn = runtime->lookupFunction(0x1280D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x128FC8u; }
        if (ctx->pc != 0x128FC8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001280D0_0x1280d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x128FC8u; }
        if (ctx->pc != 0x128FC8u) { return; }
    }
    ctx->pc = 0x128FC8u;
label_128fc8:
    // 0x128fc8: 0x1000000c  b           . + 4 + (0xC << 2)
    ctx->pc = 0x128FC8u;
    {
        const bool branch_taken_0x128fc8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x128FCCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x128FC8u;
            // 0x128fcc: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x128fc8) {
            ctx->pc = 0x128FFCu;
            goto label_128ffc;
        }
    }
    ctx->pc = 0x128FD0u;
label_128fd0:
    // 0x128fd0: 0x24020200  addiu       $v0, $zero, 0x200
    ctx->pc = 0x128fd0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 512));
    // 0x128fd4: 0xa2030000  sb          $v1, 0x0($s0)
    ctx->pc = 0x128fd4u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x128fd8: 0xa2030001  sb          $v1, 0x1($s0)
    ctx->pc = 0x128fd8u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 1), (uint8_t)GPR_U32(ctx, 3));
    // 0x128fdc: 0xae000018  sw          $zero, 0x18($s0)
    ctx->pc = 0x128fdcu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 24), GPR_U32(ctx, 0));
    // 0x128fe0: 0xae00001c  sw          $zero, 0x1C($s0)
    ctx->pc = 0x128fe0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 28), GPR_U32(ctx, 0));
    // 0x128fe4: 0xae000020  sw          $zero, 0x20($s0)
    ctx->pc = 0x128fe4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 32), GPR_U32(ctx, 0));
    // 0x128fe8: 0xa2000002  sb          $zero, 0x2($s0)
    ctx->pc = 0x128fe8u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 2), (uint8_t)GPR_U32(ctx, 0));
    // 0x128fec: 0xae000008  sw          $zero, 0x8($s0)
    ctx->pc = 0x128fecu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 8), GPR_U32(ctx, 0));
    // 0x128ff0: 0xa2000003  sb          $zero, 0x3($s0)
    ctx->pc = 0x128ff0u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 3), (uint8_t)GPR_U32(ctx, 0));
    // 0x128ff4: 0xae02002c  sw          $v0, 0x2C($s0)
    ctx->pc = 0x128ff4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 44), GPR_U32(ctx, 2));
    // 0x128ff8: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x128ff8u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_128ffc:
    // 0x128ffc: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x128ffcu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x129000: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x129000u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x129004: 0x3e00008  jr          $ra
    ctx->pc = 0x129004u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x129008u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x129004u;
            // 0x129008: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x128F94u: goto label_128f94;
            case 0x128FACu: goto label_128fac;
            case 0x128FC8u: goto label_128fc8;
            case 0x128FD0u: goto label_128fd0;
            case 0x128FFCu: goto label_128ffc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12900Cu;
    // 0x12900c: 0x0  nop
    ctx->pc = 0x12900cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
