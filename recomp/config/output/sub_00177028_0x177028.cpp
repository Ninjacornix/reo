#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00177028
// Address: 0x177028 - 0x1770ec
void sub_00177028_0x177028(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00177028_0x177028");
#endif

    switch (ctx->pc) {
        case 0x177058u: goto label_177058;
        case 0x1770ccu: goto label_1770cc;
        default: break;
    }

    ctx->pc = 0x177028u;

    // 0x177028: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x177028u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x17702c: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x17702cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x177030: 0xe0882d  daddu       $s1, $a3, $zero
    ctx->pc = 0x177030u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x177034: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x177034u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x177038: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x177038u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17703c: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x17703cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x177040: 0xc0902d  daddu       $s2, $a2, $zero
    ctx->pc = 0x177040u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x177044: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x177044u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x177048: 0xa0982d  daddu       $s3, $a1, $zero
    ctx->pc = 0x177048u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17704c: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x17704cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x177050: 0xc05a78c  jal         func_169E30
    ctx->pc = 0x177050u;
    SET_GPR_U32(ctx, 31, 0x177058u);
    ctx->pc = 0x177054u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x177050u;
            // 0x177054: 0xae200000  sw          $zero, 0x0($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169E30u;
    if (runtime->hasFunction(0x169E30u)) {
        auto targetFn = runtime->lookupFunction(0x169E30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x177058u; }
        if (ctx->pc != 0x177058u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169E30_0x169e30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x177058u; }
        if (ctx->pc != 0x177058u) { return; }
    }
    ctx->pc = 0x177058u;
label_177058:
    // 0x177058: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x177058u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17705c: 0x3c05ff00  lui         $a1, 0xFF00
    ctx->pc = 0x17705cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65280 << 16));
    // 0x177060: 0x260609a0  addiu       $a2, $s0, 0x9A0
    ctx->pc = 0x177060u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 16), 2464));
    // 0x177064: 0x10400008  beqz        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x177064u;
    {
        const bool branch_taken_0x177064 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x177068u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x177064u;
            // 0x177068: 0x34a50126  ori         $a1, $a1, 0x126 (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)294);
        ctx->in_delay_slot = false;
        if (branch_taken_0x177064) {
            ctx->pc = 0x177088u;
            goto label_177088;
        }
    }
    ctx->pc = 0x17706Cu;
    // 0x17706c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17706cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x177070: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x177070u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x177074: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x177074u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x177078: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x177078u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x17707c: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x17707cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x177080: 0x805a704  j           func_169C10
    ctx->pc = 0x177080u;
    ctx->pc = 0x177084u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x177080u;
            // 0x177084: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169C10u;
    if (runtime->hasFunction(0x169C10u)) {
        auto targetFn = runtime->lookupFunction(0x169C10u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00169C10_0x169c10(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x177088u;
label_177088:
    // 0x177088: 0x8cc30038  lw          $v1, 0x38($a2)
    ctx->pc = 0x177088u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 56)));
    // 0x17708c: 0x54600004  bnel        $v1, $zero, . + 4 + (0x4 << 2)
    ctx->pc = 0x17708Cu;
    {
        const bool branch_taken_0x17708c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x17708c) {
            ctx->pc = 0x177090u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x17708Cu;
            // 0x177090: 0x8e04004c  lw          $a0, 0x4C($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 76)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1770A0u;
            goto label_1770a0;
        }
    }
    ctx->pc = 0x177094u;
    // 0x177094: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x177094u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x177098: 0x1000000d  b           . + 4 + (0xD << 2)
    ctx->pc = 0x177098u;
    {
        const bool branch_taken_0x177098 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x17709Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x177098u;
            // 0x17709c: 0xae230000  sw          $v1, 0x0($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x177098) {
            ctx->pc = 0x1770D0u;
            goto label_1770d0;
        }
    }
    ctx->pc = 0x1770A0u;
label_1770a0:
    // 0x1770a0: 0x24030004  addiu       $v1, $zero, 0x4
    ctx->pc = 0x1770a0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1770a4: 0x50830004  beql        $a0, $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x1770A4u;
    {
        const bool branch_taken_0x1770a4 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        if (branch_taken_0x1770a4) {
            ctx->pc = 0x1770A8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1770A4u;
            // 0x1770a8: 0x8cc800b4  lw          $t0, 0xB4($a2) (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 180)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1770B8u;
            goto label_1770b8;
        }
    }
    ctx->pc = 0x1770ACu;
    // 0x1770ac: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x1770ACu;
    {
        const bool branch_taken_0x1770ac = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1770B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1770ACu;
            // 0x1770b0: 0xae200000  sw          $zero, 0x0($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1770ac) {
            ctx->pc = 0x1770D0u;
            goto label_1770d0;
        }
    }
    ctx->pc = 0x1770B4u;
    // 0x1770b4: 0x0  nop
    ctx->pc = 0x1770b4u;
    // NOP
label_1770b8:
    // 0x1770b8: 0x240302d  daddu       $a2, $s2, $zero
    ctx->pc = 0x1770b8u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1770bc: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1770bcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1770c0: 0x260282d  daddu       $a1, $s3, $zero
    ctx->pc = 0x1770c0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1770c4: 0xc05dc3c  jal         func_1770F0
    ctx->pc = 0x1770C4u;
    SET_GPR_U32(ctx, 31, 0x1770CCu);
    ctx->pc = 0x1770C8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1770C4u;
            // 0x1770c8: 0x220382d  daddu       $a3, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1770F0u;
    if (runtime->hasFunction(0x1770F0u)) {
        auto targetFn = runtime->lookupFunction(0x1770F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1770CCu; }
        if (ctx->pc != 0x1770CCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001770F0_0x1770f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1770CCu; }
        if (ctx->pc != 0x1770CCu) { return; }
    }
    ctx->pc = 0x1770CCu;
label_1770cc:
    // 0x1770cc: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1770ccu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1770d0:
    // 0x1770d0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1770d0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1770d4: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1770d4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1770d8: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x1770d8u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1770dc: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x1770dcu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1770e0: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1770e0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1770e4: 0x3e00008  jr          $ra
    ctx->pc = 0x1770E4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1770E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1770E4u;
            // 0x1770e8: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x177058u: goto label_177058;
            case 0x177088u: goto label_177088;
            case 0x1770A0u: goto label_1770a0;
            case 0x1770B8u: goto label_1770b8;
            case 0x1770CCu: goto label_1770cc;
            case 0x1770D0u: goto label_1770d0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1770ECu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
