#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00178FF8
// Address: 0x178ff8 - 0x1790f0
void sub_00178FF8_0x178ff8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00178FF8_0x178ff8");
#endif

    switch (ctx->pc) {
        case 0x179058u: goto label_179058;
        case 0x179068u: goto label_179068;
        default: break;
    }

    ctx->pc = 0x178ff8u;

label_178ff8:
    // 0x178ff8: 0x3c020024  lui         $v0, 0x24
    ctx->pc = 0x178ff8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)36 << 16));
    // 0x178ffc: 0x3e00008  jr          $ra
    ctx->pc = 0x178FFCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x179000u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x178FFCu;
            // 0x179000: 0x24420db0  addiu       $v0, $v0, 0xDB0 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 3504));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x178FF8u: goto label_178ff8;
            case 0x179058u: goto label_179058;
            case 0x179068u: goto label_179068;
            case 0x179090u: goto label_179090;
            case 0x1790E0u: goto label_1790e0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x179004u;
    // 0x179004: 0x0  nop
    ctx->pc = 0x179004u;
    // NOP
    // 0x179008: 0x38820002  xori        $v0, $a0, 0x2
    ctx->pc = 0x179008u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) ^ (uint64_t)(uint16_t)2);
    // 0x17900c: 0x3e00008  jr          $ra
    ctx->pc = 0x17900Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x179010u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17900Cu;
            // 0x179010: 0x2c420001  sltiu       $v0, $v0, 0x1 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)1) ? 1 : 0);
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x178FF8u: goto label_178ff8;
            case 0x179058u: goto label_179058;
            case 0x179068u: goto label_179068;
            case 0x179090u: goto label_179090;
            case 0x1790E0u: goto label_1790e0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x179014u;
    // 0x179014: 0x0  nop
    ctx->pc = 0x179014u;
    // NOP
    // 0x179018: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x179018u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x17901c: 0x3c020027  lui         $v0, 0x27
    ctx->pc = 0x17901cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)39 << 16));
    // 0x179020: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x179020u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x179024: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x179024u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x179028: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x179028u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x17902c: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x17902cu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x179030: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x179030u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x179034: 0x24446144  addiu       $a0, $v0, 0x6144
    ctx->pc = 0x179034u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), 24900));
    // 0x179038: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x179038u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x17903c: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x17903cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x179040: 0x1c400013  bgtz        $v0, . + 4 + (0x13 << 2)
    ctx->pc = 0x179040u;
    {
        const bool branch_taken_0x179040 = (GPR_S64(ctx, 2) > 0);
        ctx->pc = 0x179044u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x179040u;
            // 0x179044: 0x24430001  addiu       $v1, $v0, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x179040) {
            ctx->pc = 0x179090u;
            goto label_179090;
        }
    }
    ctx->pc = 0x179048u;
    // 0x179048: 0xac830000  sw          $v1, 0x0($a0)
    ctx->pc = 0x179048u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 3));
    // 0x17904c: 0x3c100027  lui         $s0, 0x27
    ctx->pc = 0x17904cu;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)39 << 16));
    // 0x179050: 0xc05e3fe  jal         func_178FF8
    ctx->pc = 0x179050u;
    SET_GPR_U32(ctx, 31, 0x179058u);
    ctx->pc = 0x179054u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x179050u;
            // 0x179054: 0x26106130  addiu       $s0, $s0, 0x6130 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 24880));
        ctx->in_delay_slot = false;
    ctx->pc = 0x178FF8u;
    goto label_178ff8;
    ctx->pc = 0x179058u;
label_179058:
    // 0x179058: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x179058u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17905c: 0xae020000  sw          $v0, 0x0($s0)
    ctx->pc = 0x17905cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 2));
    // 0x179060: 0xc05e48e  jal         func_179238
    ctx->pc = 0x179060u;
    SET_GPR_U32(ctx, 31, 0x179068u);
    ctx->pc = 0x179064u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x179060u;
            // 0x179064: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x179238u;
    if (runtime->hasFunction(0x179238u)) {
        auto targetFn = runtime->lookupFunction(0x179238u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x179068u; }
        if (ctx->pc != 0x179068u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00179238_0x179238(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x179068u; }
        if (ctx->pc != 0x179068u) { return; }
    }
    ctx->pc = 0x179068u;
label_179068:
    // 0x179068: 0x3c040027  lui         $a0, 0x27
    ctx->pc = 0x179068u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)39 << 16));
    // 0x17906c: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x17906cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x179070: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x179070u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x179074: 0x220302d  daddu       $a2, $s1, $zero
    ctx->pc = 0x179074u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x179078: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x179078u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x17907c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17907cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x179080: 0x24846138  addiu       $a0, $a0, 0x6138
    ctx->pc = 0x179080u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 24888));
    // 0x179084: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x179084u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x179088: 0x805e47e  j           func_1791F8
    ctx->pc = 0x179088u;
    ctx->pc = 0x17908Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x179088u;
            // 0x17908c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1791F8u;
    if (runtime->hasFunction(0x1791F8u)) {
        auto targetFn = runtime->lookupFunction(0x1791F8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001791F8_0x1791f8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x179090u;
label_179090:
    // 0x179090: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x179090u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x179094: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x179094u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x179098: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x179098u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17909c: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x17909cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1790a0: 0x3e00008  jr          $ra
    ctx->pc = 0x1790A0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1790A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1790A0u;
            // 0x1790a4: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x178FF8u: goto label_178ff8;
            case 0x179058u: goto label_179058;
            case 0x179068u: goto label_179068;
            case 0x179090u: goto label_179090;
            case 0x1790E0u: goto label_1790e0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1790A8u;
    // 0x1790a8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1790a8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1790ac: 0x3c030027  lui         $v1, 0x27
    ctx->pc = 0x1790acu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)39 << 16));
    // 0x1790b0: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1790b0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1790b4: 0x24636144  addiu       $v1, $v1, 0x6144
    ctx->pc = 0x1790b4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 24900));
    // 0x1790b8: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x1790b8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1790bc: 0x2442ffff  addiu       $v0, $v0, -0x1
    ctx->pc = 0x1790bcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x1790c0: 0x1c400007  bgtz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1790C0u;
    {
        const bool branch_taken_0x1790c0 = (GPR_S64(ctx, 2) > 0);
        ctx->pc = 0x1790C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1790C0u;
            // 0x1790c4: 0xac620000  sw          $v0, 0x0($v1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1790c0) {
            ctx->pc = 0x1790E0u;
            goto label_1790e0;
        }
    }
    ctx->pc = 0x1790C8u;
    // 0x1790c8: 0x3c040027  lui         $a0, 0x27
    ctx->pc = 0x1790c8u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)39 << 16));
    // 0x1790cc: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1790ccu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1790d0: 0x24846138  addiu       $a0, $a0, 0x6138
    ctx->pc = 0x1790d0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 24888));
    // 0x1790d4: 0x805e47a  j           func_1791E8
    ctx->pc = 0x1790D4u;
    ctx->pc = 0x1790D8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1790D4u;
            // 0x1790d8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1791E8u;
    if (runtime->hasFunction(0x1791E8u)) {
        auto targetFn = runtime->lookupFunction(0x1791E8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001791E8_0x1791e8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1790DCu;
    // 0x1790dc: 0x0  nop
    ctx->pc = 0x1790dcu;
    // NOP
label_1790e0:
    // 0x1790e0: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1790e0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1790e4: 0x3e00008  jr          $ra
    ctx->pc = 0x1790E4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1790E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1790E4u;
            // 0x1790e8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x178FF8u: goto label_178ff8;
            case 0x179058u: goto label_179058;
            case 0x179068u: goto label_179068;
            case 0x179090u: goto label_179090;
            case 0x1790E0u: goto label_1790e0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1790ECu;
    // 0x1790ec: 0x0  nop
    ctx->pc = 0x1790ecu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
