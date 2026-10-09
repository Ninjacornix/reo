#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00148E98
// Address: 0x148e98 - 0x1491c8
void sub_00148E98_0x148e98(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00148E98_0x148e98");
#endif

    switch (ctx->pc) {
        case 0x148eccu: goto label_148ecc;
        case 0x148ed4u: goto label_148ed4;
        case 0x148ee8u: goto label_148ee8;
        case 0x148ef0u: goto label_148ef0;
        case 0x148f38u: goto label_148f38;
        case 0x148f44u: goto label_148f44;
        case 0x148f4cu: goto label_148f4c;
        case 0x148f60u: goto label_148f60;
        case 0x148facu: goto label_148fac;
        case 0x148fb8u: goto label_148fb8;
        case 0x148ff4u: goto label_148ff4;
        case 0x149010u: goto label_149010;
        case 0x14903cu: goto label_14903c;
        case 0x1490c0u: goto label_1490c0;
        case 0x1490ccu: goto label_1490cc;
        case 0x1490dcu: goto label_1490dc;
        case 0x1490e8u: goto label_1490e8;
        case 0x1490f4u: goto label_1490f4;
        case 0x149104u: goto label_149104;
        case 0x149114u: goto label_149114;
        case 0x149120u: goto label_149120;
        case 0x14918cu: goto label_14918c;
        case 0x1491b4u: goto label_1491b4;
        default: break;
    }

    ctx->pc = 0x148e98u;

    // 0x148e98: 0x27bdffa0  addiu       $sp, $sp, -0x60
    ctx->pc = 0x148e98u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967200));
    // 0x148e9c: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x148e9cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x148ea0: 0xffb20040  sd          $s2, 0x40($sp)
    ctx->pc = 0x148ea0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 18));
    // 0x148ea4: 0xffb10030  sd          $s1, 0x30($sp)
    ctx->pc = 0x148ea4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 17));
    // 0x148ea8: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x148ea8u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x148eac: 0xffb00020  sd          $s0, 0x20($sp)
    ctx->pc = 0x148eacu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 16));
    // 0x148eb0: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x148eb0u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x148eb4: 0xffbf0050  sd          $ra, 0x50($sp)
    ctx->pc = 0x148eb4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 31));
    // 0x148eb8: 0xc0802d  daddu       $s0, $a2, $zero
    ctx->pc = 0x148eb8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x148ebc: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x148ebcu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x148ec0: 0x8e240870  lw          $a0, 0x870($s1)
    ctx->pc = 0x148ec0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 2160)));
    // 0x148ec4: 0xc051fda  jal         func_147F68
    ctx->pc = 0x148EC4u;
    SET_GPR_U32(ctx, 31, 0x148ECCu);
    ctx->pc = 0x148EC8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x148EC4u;
            // 0x148ec8: 0xafa20000  sw          $v0, 0x0($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x147F68u;
    if (runtime->hasFunction(0x147F68u)) {
        auto targetFn = runtime->lookupFunction(0x147F68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x148ECCu; }
        if (ctx->pc != 0x148ECCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00147F68_0x147f68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x148ECCu; }
        if (ctx->pc != 0x148ECCu) { return; }
    }
    ctx->pc = 0x148ECCu;
label_148ecc:
    // 0x148ecc: 0xc051496  jal         func_145258
    ctx->pc = 0x148ECCu;
    SET_GPR_U32(ctx, 31, 0x148ED4u);
    ctx->pc = 0x148ED0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x148ECCu;
            // 0x148ed0: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x145258u;
    if (runtime->hasFunction(0x145258u)) {
        auto targetFn = runtime->lookupFunction(0x145258u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x148ED4u; }
        if (ctx->pc != 0x148ED4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00145258_0x145258(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x148ED4u; }
        if (ctx->pc != 0x148ED4u) { return; }
    }
    ctx->pc = 0x148ED4u;
label_148ed4:
    // 0x148ed4: 0x3c021000  lui         $v0, 0x1000
    ctx->pc = 0x148ed4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)4096 << 16));
    // 0x148ed8: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x148ed8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x148edc: 0x34422000  ori         $v0, $v0, 0x2000
    ctx->pc = 0x148edcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)8192);
    // 0x148ee0: 0xc051496  jal         func_145258
    ctx->pc = 0x148EE0u;
    SET_GPR_U32(ctx, 31, 0x148EE8u);
    ctx->pc = 0x148EE4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x148EE0u;
            // 0x148ee4: 0xac400000  sw          $zero, 0x0($v0) (Delay Slot)
        runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x145258u;
    if (runtime->hasFunction(0x145258u)) {
        auto targetFn = runtime->lookupFunction(0x145258u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x148EE8u; }
        if (ctx->pc != 0x148EE8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00145258_0x145258(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x148EE8u; }
        if (ctx->pc != 0x148EE8u) { return; }
    }
    ctx->pc = 0x148EE8u;
label_148ee8:
    // 0x148ee8: 0xc047598  jal         func_11D660
    ctx->pc = 0x148EE8u;
    SET_GPR_U32(ctx, 31, 0x148EF0u);
    ctx->pc = 0x11D660u;
    if (runtime->hasFunction(0x11D660u)) {
        auto targetFn = runtime->lookupFunction(0x11D660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x148EF0u; }
        if (ctx->pc != 0x148EF0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D660_0x11d660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x148EF0u; }
        if (ctx->pc != 0x148EF0u) { return; }
    }
    ctx->pc = 0x148EF0u;
label_148ef0:
    // 0x148ef0: 0x3c030fff  lui         $v1, 0xFFF
    ctx->pc = 0x148ef0u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)4095 << 16));
    // 0x148ef4: 0x3c041000  lui         $a0, 0x1000
    ctx->pc = 0x148ef4u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)4096 << 16));
    // 0x148ef8: 0x3463ffff  ori         $v1, $v1, 0xFFFF
    ctx->pc = 0x148ef8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)65535);
    // 0x148efc: 0x3484b410  ori         $a0, $a0, 0xB410
    ctx->pc = 0x148efcu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)46096);
    // 0x148f00: 0x2038024  and         $s0, $s0, $v1
    ctx->pc = 0x148f00u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) & GPR_U64(ctx, 3));
    // 0x148f04: 0x3c051000  lui         $a1, 0x1000
    ctx->pc = 0x148f04u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)4096 << 16));
    // 0x148f08: 0xac900000  sw          $s0, 0x0($a0)
    ctx->pc = 0x148f08u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 16)); // MMIO: 0x10000000
    // 0x148f0c: 0x34a5b420  ori         $a1, $a1, 0xB420
    ctx->pc = 0x148f0cu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)46112);
    // 0x148f10: 0x24040004  addiu       $a0, $zero, 0x4
    ctx->pc = 0x148f10u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x148f14: 0x3c031000  lui         $v1, 0x1000
    ctx->pc = 0x148f14u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)4096 << 16));
    // 0x148f18: 0xaca40000  sw          $a0, 0x0($a1)
    ctx->pc = 0x148f18u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 4)); // MMIO: 0x10000000
    // 0x148f1c: 0x3463b400  ori         $v1, $v1, 0xB400
    ctx->pc = 0x148f1cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)46080);
    // 0x148f20: 0x24040101  addiu       $a0, $zero, 0x101
    ctx->pc = 0x148f20u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 257));
    // 0x148f24: 0xac640000  sw          $a0, 0x0($v1)
    ctx->pc = 0x148f24u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 4)); // MMIO: 0x10000000
    // 0x148f28: 0x50400004  beql        $v0, $zero, . + 4 + (0x4 << 2)
    ctx->pc = 0x148F28u;
    {
        const bool branch_taken_0x148f28 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x148f28) {
            ctx->pc = 0x148F2Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x148F28u;
            // 0x148f2c: 0x240282d  daddu       $a1, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x148F3Cu;
            goto label_148f3c;
        }
    }
    ctx->pc = 0x148F30u;
    // 0x148f30: 0xc0475ae  jal         func_11D6B8
    ctx->pc = 0x148F30u;
    SET_GPR_U32(ctx, 31, 0x148F38u);
    ctx->pc = 0x11D6B8u;
    if (runtime->hasFunction(0x11D6B8u)) {
        auto targetFn = runtime->lookupFunction(0x11D6B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x148F38u; }
        if (ctx->pc != 0x148F38u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D6B8_0x11d6b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x148F38u; }
        if (ctx->pc != 0x148F38u) { return; }
    }
    ctx->pc = 0x148F38u;
label_148f38:
    // 0x148f38: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x148f38u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
label_148f3c:
    // 0x148f3c: 0xc05148a  jal         func_145228
    ctx->pc = 0x148F3Cu;
    SET_GPR_U32(ctx, 31, 0x148F44u);
    ctx->pc = 0x148F40u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x148F3Cu;
            // 0x148f40: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x145228u;
    if (runtime->hasFunction(0x145228u)) {
        auto targetFn = runtime->lookupFunction(0x145228u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x148F44u; }
        if (ctx->pc != 0x148F44u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00145228_0x145228(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x148F44u; }
        if (ctx->pc != 0x148F44u) { return; }
    }
    ctx->pc = 0x148F44u;
label_148f44:
    // 0x148f44: 0xc051496  jal         func_145258
    ctx->pc = 0x148F44u;
    SET_GPR_U32(ctx, 31, 0x148F4Cu);
    ctx->pc = 0x148F48u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x148F44u;
            // 0x148f48: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x145258u;
    if (runtime->hasFunction(0x145258u)) {
        auto targetFn = runtime->lookupFunction(0x145258u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x148F4Cu; }
        if (ctx->pc != 0x148F4Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00145258_0x145258(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x148F4Cu; }
        if (ctx->pc != 0x148F4Cu) { return; }
    }
    ctx->pc = 0x148F4Cu;
label_148f4c:
    // 0x148f4c: 0x8e240870  lw          $a0, 0x870($s1)
    ctx->pc = 0x148f4cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 2160)));
    // 0x148f50: 0x24020003  addiu       $v0, $zero, 0x3
    ctx->pc = 0x148f50u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x148f54: 0xafa20000  sw          $v0, 0x0($sp)
    ctx->pc = 0x148f54u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 2));
    // 0x148f58: 0xc051fda  jal         func_147F68
    ctx->pc = 0x148F58u;
    SET_GPR_U32(ctx, 31, 0x148F60u);
    ctx->pc = 0x148F5Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x148F58u;
            // 0x148f5c: 0x3a0282d  daddu       $a1, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x147F68u;
    if (runtime->hasFunction(0x147F68u)) {
        auto targetFn = runtime->lookupFunction(0x147F68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x148F60u; }
        if (ctx->pc != 0x148F60u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00147F68_0x147f68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x148F60u; }
        if (ctx->pc != 0x148F60u) { return; }
    }
    ctx->pc = 0x148F60u;
label_148f60:
    // 0x148f60: 0xdfbf0050  ld          $ra, 0x50($sp)
    ctx->pc = 0x148f60u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x148f64: 0xdfb20040  ld          $s2, 0x40($sp)
    ctx->pc = 0x148f64u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x148f68: 0xdfb10030  ld          $s1, 0x30($sp)
    ctx->pc = 0x148f68u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x148f6c: 0xdfb00020  ld          $s0, 0x20($sp)
    ctx->pc = 0x148f6cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x148f70: 0x3e00008  jr          $ra
    ctx->pc = 0x148F70u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x148F74u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x148F70u;
            // 0x148f74: 0x27bd0060  addiu       $sp, $sp, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x148ECCu: goto label_148ecc;
            case 0x148ED4u: goto label_148ed4;
            case 0x148EE8u: goto label_148ee8;
            case 0x148EF0u: goto label_148ef0;
            case 0x148F38u: goto label_148f38;
            case 0x148F3Cu: goto label_148f3c;
            case 0x148F44u: goto label_148f44;
            case 0x148F4Cu: goto label_148f4c;
            case 0x148F60u: goto label_148f60;
            case 0x148FACu: goto label_148fac;
            case 0x148FB8u: goto label_148fb8;
            case 0x148FF4u: goto label_148ff4;
            case 0x149010u: goto label_149010;
            case 0x14903Cu: goto label_14903c;
            case 0x1490C0u: goto label_1490c0;
            case 0x1490CCu: goto label_1490cc;
            case 0x1490DCu: goto label_1490dc;
            case 0x1490E8u: goto label_1490e8;
            case 0x1490F4u: goto label_1490f4;
            case 0x1490F8u: goto label_1490f8;
            case 0x149104u: goto label_149104;
            case 0x149114u: goto label_149114;
            case 0x149120u: goto label_149120;
            case 0x14918Cu: goto label_14918c;
            case 0x1491B4u: goto label_1491b4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x148F78u;
    // 0x148f78: 0x27bdff90  addiu       $sp, $sp, -0x70
    ctx->pc = 0x148f78u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967184));
    // 0x148f7c: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x148f7cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x148f80: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x148f80u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x148f84: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x148f84u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x148f88: 0xffb50050  sd          $s5, 0x50($sp)
    ctx->pc = 0x148f88u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 21));
    // 0x148f8c: 0x24100001  addiu       $s0, $zero, 0x1
    ctx->pc = 0x148f8cu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x148f90: 0xffb40040  sd          $s4, 0x40($sp)
    ctx->pc = 0x148f90u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 20));
    // 0x148f94: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x148f94u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x148f98: 0xffb30030  sd          $s3, 0x30($sp)
    ctx->pc = 0x148f98u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 19));
    // 0x148f9c: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x148f9cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x148fa0: 0xffbf0060  sd          $ra, 0x60($sp)
    ctx->pc = 0x148fa0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 31));
    // 0x148fa4: 0xc050fe2  jal         func_143F88
    ctx->pc = 0x148FA4u;
    SET_GPR_U32(ctx, 31, 0x148FACu);
    ctx->pc = 0x148FA8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x148FA4u;
            // 0x148fa8: 0xae300860  sw          $s0, 0x860($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 2144), GPR_U32(ctx, 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x143F88u;
    if (runtime->hasFunction(0x143F88u)) {
        auto targetFn = runtime->lookupFunction(0x143F88u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x148FACu; }
        if (ctx->pc != 0x148FACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00143F88_0x143f88(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x148FACu; }
        if (ctx->pc != 0x148FACu) { return; }
    }
    ctx->pc = 0x148FACu;
label_148fac:
    // 0x148fac: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x148facu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x148fb0: 0xc05167a  jal         func_1459E8
    ctx->pc = 0x148FB0u;
    SET_GPR_U32(ctx, 31, 0x148FB8u);
    ctx->pc = 0x148FB4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x148FB0u;
            // 0x148fb4: 0x2405001c  addiu       $a1, $zero, 0x1C (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 28));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1459E8u;
    if (runtime->hasFunction(0x1459E8u)) {
        auto targetFn = runtime->lookupFunction(0x1459E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x148FB8u; }
        if (ctx->pc != 0x148FB8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001459E8_0x1459e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x148FB8u; }
        if (ctx->pc != 0x148FB8u) { return; }
    }
    ctx->pc = 0x148FB8u;
label_148fb8:
    // 0x148fb8: 0x40902d  daddu       $s2, $v0, $zero
    ctx->pc = 0x148fb8u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x148fbc: 0x121842  srl         $v1, $s2, 1
    ctx->pc = 0x148fbcu;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 18), 1));
    // 0x148fc0: 0x121442  srl         $v0, $s2, 17
    ctx->pc = 0x148fc0u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 17));
    // 0x148fc4: 0x30750fff  andi        $s5, $v1, 0xFFF
    ctx->pc = 0x148fc4u;
    SET_GPR_U64(ctx, 21, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)4095);
    // 0x148fc8: 0x30420003  andi        $v0, $v0, 0x3
    ctx->pc = 0x148fc8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)3);
    // 0x148fcc: 0x122342  srl         $a0, $s2, 13
    ctx->pc = 0x148fccu;
    SET_GPR_S32(ctx, 4, (int32_t)SRL32(GPR_U32(ctx, 18), 13));
    // 0x148fd0: 0x121bc2  srl         $v1, $s2, 15
    ctx->pc = 0x148fd0u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 18), 15));
    // 0x148fd4: 0x30940003  andi        $s4, $a0, 0x3
    ctx->pc = 0x148fd4u;
    SET_GPR_U64(ctx, 20, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)3);
    // 0x148fd8: 0x30730003  andi        $s3, $v1, 0x3
    ctx->pc = 0x148fd8u;
    SET_GPR_U64(ctx, 19, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)3);
    // 0x148fdc: 0x10500005  beq         $v0, $s0, . + 4 + (0x5 << 2)
    ctx->pc = 0x148FDCu;
    {
        const bool branch_taken_0x148fdc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 16));
        ctx->pc = 0x148FE0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x148FDCu;
            // 0x148fe0: 0xae220158  sw          $v0, 0x158($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 344), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x148fdc) {
            ctx->pc = 0x148FF4u;
            goto label_148ff4;
        }
    }
    ctx->pc = 0x148FE4u;
    // 0x148fe4: 0x3c050024  lui         $a1, 0x24
    ctx->pc = 0x148fe4u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)36 << 16));
    // 0x148fe8: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x148fe8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x148fec: 0xc05221c  jal         func_148870
    ctx->pc = 0x148FECu;
    SET_GPR_U32(ctx, 31, 0x148FF4u);
    ctx->pc = 0x148FF0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x148FECu;
            // 0x148ff0: 0x24a5e160  addiu       $a1, $a1, -0x1EA0 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294959456));
        ctx->in_delay_slot = false;
    ctx->pc = 0x148870u;
    if (runtime->hasFunction(0x148870u)) {
        auto targetFn = runtime->lookupFunction(0x148870u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x148FF4u; }
        if (ctx->pc != 0x148FF4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00148870_0x148870(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x148FF4u; }
        if (ctx->pc != 0x148FF4u) { return; }
    }
    ctx->pc = 0x148FF4u;
label_148ff4:
    // 0x148ff4: 0x1214c2  srl         $v0, $s2, 19
    ctx->pc = 0x148ff4u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 19));
    // 0x148ff8: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x148ff8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x148ffc: 0x30420001  andi        $v0, $v0, 0x1
    ctx->pc = 0x148ffcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)1);
    // 0x149000: 0x24050010  addiu       $a1, $zero, 0x10
    ctx->pc = 0x149000u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x149004: 0xae220154  sw          $v0, 0x154($s1)
    ctx->pc = 0x149004u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 340), GPR_U32(ctx, 2));
    // 0x149008: 0xc05167a  jal         func_1459E8
    ctx->pc = 0x149008u;
    SET_GPR_U32(ctx, 31, 0x149010u);
    ctx->pc = 0x14900Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x149008u;
            // 0x14900c: 0x128502  srl         $s0, $s2, 20 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)SRL32(GPR_U32(ctx, 18), 20));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1459E8u;
    if (runtime->hasFunction(0x1459E8u)) {
        auto targetFn = runtime->lookupFunction(0x1459E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x149010u; }
        if (ctx->pc != 0x149010u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001459E8_0x1459e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x149010u; }
        if (ctx->pc != 0x149010u) { return; }
    }
    ctx->pc = 0x149010u;
label_149010:
    // 0x149010: 0x29202  srl         $s2, $v0, 8
    ctx->pc = 0x149010u;
    SET_GPR_S32(ctx, 18, (int32_t)SRL32(GPR_U32(ctx, 2), 8));
    // 0x149014: 0x24020048  addiu       $v0, $zero, 0x48
    ctx->pc = 0x149014u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 72));
    // 0x149018: 0x12020008  beq         $s0, $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x149018u;
    {
        const bool branch_taken_0x149018 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 2));
        ctx->pc = 0x14901Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x149018u;
            // 0x14901c: 0x24020058  addiu       $v0, $zero, 0x58 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 88));
        ctx->in_delay_slot = false;
        if (branch_taken_0x149018) {
            ctx->pc = 0x14903Cu;
            goto label_14903c;
        }
    }
    ctx->pc = 0x149020u;
    // 0x149020: 0x12020006  beq         $s0, $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x149020u;
    {
        const bool branch_taken_0x149020 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 2));
        ctx->pc = 0x149024u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x149020u;
            // 0x149024: 0x24020044  addiu       $v0, $zero, 0x44 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 68));
        ctx->in_delay_slot = false;
        if (branch_taken_0x149020) {
            ctx->pc = 0x14903Cu;
            goto label_14903c;
        }
    }
    ctx->pc = 0x149028u;
    // 0x149028: 0x12020004  beq         $s0, $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x149028u;
    {
        const bool branch_taken_0x149028 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 2));
        ctx->pc = 0x14902Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x149028u;
            // 0x14902c: 0x3c050024  lui         $a1, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x149028) {
            ctx->pc = 0x14903Cu;
            goto label_14903c;
        }
    }
    ctx->pc = 0x149030u;
    // 0x149030: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x149030u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x149034: 0xc05221c  jal         func_148870
    ctx->pc = 0x149034u;
    SET_GPR_U32(ctx, 31, 0x14903Cu);
    ctx->pc = 0x149038u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x149034u;
            // 0x149038: 0x24a5e188  addiu       $a1, $a1, -0x1E78 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294959496));
        ctx->in_delay_slot = false;
    ctx->pc = 0x148870u;
    if (runtime->hasFunction(0x148870u)) {
        auto targetFn = runtime->lookupFunction(0x148870u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14903Cu; }
        if (ctx->pc != 0x14903Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00148870_0x148870(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14903Cu; }
        if (ctx->pc != 0x14903Cu) { return; }
    }
    ctx->pc = 0x14903Cu;
label_14903c:
    // 0x14903c: 0x8e24013c  lw          $a0, 0x13C($s1)
    ctx->pc = 0x14903cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 316)));
    // 0x149040: 0x154480  sll         $t0, $s5, 18
    ctx->pc = 0x149040u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 21), 18));
    // 0x149044: 0x8e230140  lw          $v1, 0x140($s1)
    ctx->pc = 0x149044u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 320)));
    // 0x149048: 0x124a80  sll         $t1, $s2, 10
    ctx->pc = 0x149048u;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 18), 10));
    // 0x14904c: 0x8e26014c  lw          $a2, 0x14C($s1)
    ctx->pc = 0x14904cu;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 332)));
    // 0x149050: 0x133b00  sll         $a3, $s3, 12
    ctx->pc = 0x149050u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 19), 12));
    // 0x149054: 0x8e220150  lw          $v0, 0x150($s1)
    ctx->pc = 0x149054u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 336)));
    // 0x149058: 0x142b00  sll         $a1, $s4, 12
    ctx->pc = 0x149058u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 20), 12));
    // 0x14905c: 0x30840fff  andi        $a0, $a0, 0xFFF
    ctx->pc = 0x14905cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)4095);
    // 0x149060: 0x30630fff  andi        $v1, $v1, 0xFFF
    ctx->pc = 0x149060u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)4095);
    // 0x149064: 0xe43825  or          $a3, $a3, $a0
    ctx->pc = 0x149064u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 4));
    // 0x149068: 0xa32825  or          $a1, $a1, $v1
    ctx->pc = 0x149068u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | GPR_U64(ctx, 3));
    // 0x14906c: 0xc83021  addu        $a2, $a2, $t0
    ctx->pc = 0x14906cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 8)));
    // 0x149070: 0x491021  addu        $v0, $v0, $t1
    ctx->pc = 0x149070u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 9)));
    // 0x149074: 0xae220150  sw          $v0, 0x150($s1)
    ctx->pc = 0x149074u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 336), GPR_U32(ctx, 2));
    // 0x149078: 0xae27013c  sw          $a3, 0x13C($s1)
    ctx->pc = 0x149078u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 316), GPR_U32(ctx, 7));
    // 0x14907c: 0xae250140  sw          $a1, 0x140($s1)
    ctx->pc = 0x14907cu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 320), GPR_U32(ctx, 5));
    // 0x149080: 0xae26014c  sw          $a2, 0x14C($s1)
    ctx->pc = 0x149080u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 332), GPR_U32(ctx, 6));
    // 0x149084: 0xdfbf0060  ld          $ra, 0x60($sp)
    ctx->pc = 0x149084u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x149088: 0xdfb50050  ld          $s5, 0x50($sp)
    ctx->pc = 0x149088u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x14908c: 0xdfb40040  ld          $s4, 0x40($sp)
    ctx->pc = 0x14908cu;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x149090: 0xdfb30030  ld          $s3, 0x30($sp)
    ctx->pc = 0x149090u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x149094: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x149094u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x149098: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x149098u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x14909c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x14909cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1490a0: 0x3e00008  jr          $ra
    ctx->pc = 0x1490A0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1490A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1490A0u;
            // 0x1490a4: 0x27bd0070  addiu       $sp, $sp, 0x70 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 112));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x148ECCu: goto label_148ecc;
            case 0x148ED4u: goto label_148ed4;
            case 0x148EE8u: goto label_148ee8;
            case 0x148EF0u: goto label_148ef0;
            case 0x148F38u: goto label_148f38;
            case 0x148F3Cu: goto label_148f3c;
            case 0x148F44u: goto label_148f44;
            case 0x148F4Cu: goto label_148f4c;
            case 0x148F60u: goto label_148f60;
            case 0x148FACu: goto label_148fac;
            case 0x148FB8u: goto label_148fb8;
            case 0x148FF4u: goto label_148ff4;
            case 0x149010u: goto label_149010;
            case 0x14903Cu: goto label_14903c;
            case 0x1490C0u: goto label_1490c0;
            case 0x1490CCu: goto label_1490cc;
            case 0x1490DCu: goto label_1490dc;
            case 0x1490E8u: goto label_1490e8;
            case 0x1490F4u: goto label_1490f4;
            case 0x1490F8u: goto label_1490f8;
            case 0x149104u: goto label_149104;
            case 0x149114u: goto label_149114;
            case 0x149120u: goto label_149120;
            case 0x14918Cu: goto label_14918c;
            case 0x1491B4u: goto label_1491b4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1490A8u;
    // 0x1490a8: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1490a8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1490ac: 0x24050003  addiu       $a1, $zero, 0x3
    ctx->pc = 0x1490acu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1490b0: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1490b0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1490b4: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1490b4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1490b8: 0xc05167a  jal         func_1459E8
    ctx->pc = 0x1490B8u;
    SET_GPR_U32(ctx, 31, 0x1490C0u);
    ctx->pc = 0x1490BCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1490B8u;
            // 0x1490bc: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1459E8u;
    if (runtime->hasFunction(0x1459E8u)) {
        auto targetFn = runtime->lookupFunction(0x1459E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1490C0u; }
        if (ctx->pc != 0x1490C0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001459E8_0x1459e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1490C0u; }
        if (ctx->pc != 0x1490C0u) { return; }
    }
    ctx->pc = 0x1490C0u;
label_1490c0:
    // 0x1490c0: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1490c0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1490c4: 0xc05167a  jal         func_1459E8
    ctx->pc = 0x1490C4u;
    SET_GPR_U32(ctx, 31, 0x1490CCu);
    ctx->pc = 0x1490C8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1490C4u;
            // 0x1490c8: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1459E8u;
    if (runtime->hasFunction(0x1459E8u)) {
        auto targetFn = runtime->lookupFunction(0x1459E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1490CCu; }
        if (ctx->pc != 0x1490CCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001459E8_0x1459e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1490CCu; }
        if (ctx->pc != 0x1490CCu) { return; }
    }
    ctx->pc = 0x1490CCu;
label_1490cc:
    // 0x1490cc: 0x1040000a  beqz        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x1490CCu;
    {
        const bool branch_taken_0x1490cc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1490D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1490CCu;
            // 0x1490d0: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1490cc) {
            ctx->pc = 0x1490F8u;
            goto label_1490f8;
        }
    }
    ctx->pc = 0x1490D4u;
    // 0x1490d4: 0xc05167a  jal         func_1459E8
    ctx->pc = 0x1490D4u;
    SET_GPR_U32(ctx, 31, 0x1490DCu);
    ctx->pc = 0x1490D8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1490D4u;
            // 0x1490d8: 0x24050008  addiu       $a1, $zero, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1459E8u;
    if (runtime->hasFunction(0x1459E8u)) {
        auto targetFn = runtime->lookupFunction(0x1459E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1490DCu; }
        if (ctx->pc != 0x1490DCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001459E8_0x1459e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1490DCu; }
        if (ctx->pc != 0x1490DCu) { return; }
    }
    ctx->pc = 0x1490DCu;
label_1490dc:
    // 0x1490dc: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1490dcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1490e0: 0xc05167a  jal         func_1459E8
    ctx->pc = 0x1490E0u;
    SET_GPR_U32(ctx, 31, 0x1490E8u);
    ctx->pc = 0x1490E4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1490E0u;
            // 0x1490e4: 0x24050008  addiu       $a1, $zero, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1459E8u;
    if (runtime->hasFunction(0x1459E8u)) {
        auto targetFn = runtime->lookupFunction(0x1459E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1490E8u; }
        if (ctx->pc != 0x1490E8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001459E8_0x1459e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1490E8u; }
        if (ctx->pc != 0x1490E8u) { return; }
    }
    ctx->pc = 0x1490E8u;
label_1490e8:
    // 0x1490e8: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1490e8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1490ec: 0xc05167a  jal         func_1459E8
    ctx->pc = 0x1490ECu;
    SET_GPR_U32(ctx, 31, 0x1490F4u);
    ctx->pc = 0x1490F0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1490ECu;
            // 0x1490f0: 0x24050008  addiu       $a1, $zero, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1459E8u;
    if (runtime->hasFunction(0x1459E8u)) {
        auto targetFn = runtime->lookupFunction(0x1459E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1490F4u; }
        if (ctx->pc != 0x1490F4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001459E8_0x1459e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1490F4u; }
        if (ctx->pc != 0x1490F4u) { return; }
    }
    ctx->pc = 0x1490F4u;
label_1490f4:
    // 0x1490f4: 0xae02015c  sw          $v0, 0x15C($s0)
    ctx->pc = 0x1490f4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 348), GPR_U32(ctx, 2));
label_1490f8:
    // 0x1490f8: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1490f8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1490fc: 0xc05167a  jal         func_1459E8
    ctx->pc = 0x1490FCu;
    SET_GPR_U32(ctx, 31, 0x149104u);
    ctx->pc = 0x149100u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1490FCu;
            // 0x149100: 0x2405000e  addiu       $a1, $zero, 0xE (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 14));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1459E8u;
    if (runtime->hasFunction(0x1459E8u)) {
        auto targetFn = runtime->lookupFunction(0x1459E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x149104u; }
        if (ctx->pc != 0x149104u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001459E8_0x1459e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x149104u; }
        if (ctx->pc != 0x149104u) { return; }
    }
    ctx->pc = 0x149104u;
label_149104:
    // 0x149104: 0xae020160  sw          $v0, 0x160($s0)
    ctx->pc = 0x149104u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 352), GPR_U32(ctx, 2));
    // 0x149108: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x149108u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x14910c: 0xc05167a  jal         func_1459E8
    ctx->pc = 0x14910Cu;
    SET_GPR_U32(ctx, 31, 0x149114u);
    ctx->pc = 0x149110u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x14910Cu;
            // 0x149110: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1459E8u;
    if (runtime->hasFunction(0x1459E8u)) {
        auto targetFn = runtime->lookupFunction(0x1459E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x149114u; }
        if (ctx->pc != 0x149114u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001459E8_0x1459e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x149114u; }
        if (ctx->pc != 0x149114u) { return; }
    }
    ctx->pc = 0x149114u;
label_149114:
    // 0x149114: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x149114u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x149118: 0xc05167a  jal         func_1459E8
    ctx->pc = 0x149118u;
    SET_GPR_U32(ctx, 31, 0x149120u);
    ctx->pc = 0x14911Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x149118u;
            // 0x14911c: 0x2405000e  addiu       $a1, $zero, 0xE (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 14));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1459E8u;
    if (runtime->hasFunction(0x1459E8u)) {
        auto targetFn = runtime->lookupFunction(0x1459E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x149120u; }
        if (ctx->pc != 0x149120u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001459E8_0x1459e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x149120u; }
        if (ctx->pc != 0x149120u) { return; }
    }
    ctx->pc = 0x149120u;
label_149120:
    // 0x149120: 0xae020164  sw          $v0, 0x164($s0)
    ctx->pc = 0x149120u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 356), GPR_U32(ctx, 2));
    // 0x149124: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x149124u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x149128: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x149128u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x14912c: 0x3e00008  jr          $ra
    ctx->pc = 0x14912Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x149130u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x14912Cu;
            // 0x149130: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x148ECCu: goto label_148ecc;
            case 0x148ED4u: goto label_148ed4;
            case 0x148EE8u: goto label_148ee8;
            case 0x148EF0u: goto label_148ef0;
            case 0x148F38u: goto label_148f38;
            case 0x148F3Cu: goto label_148f3c;
            case 0x148F44u: goto label_148f44;
            case 0x148F4Cu: goto label_148f4c;
            case 0x148F60u: goto label_148f60;
            case 0x148FACu: goto label_148fac;
            case 0x148FB8u: goto label_148fb8;
            case 0x148FF4u: goto label_148ff4;
            case 0x149010u: goto label_149010;
            case 0x14903Cu: goto label_14903c;
            case 0x1490C0u: goto label_1490c0;
            case 0x1490CCu: goto label_1490cc;
            case 0x1490DCu: goto label_1490dc;
            case 0x1490E8u: goto label_1490e8;
            case 0x1490F4u: goto label_1490f4;
            case 0x1490F8u: goto label_1490f8;
            case 0x149104u: goto label_149104;
            case 0x149114u: goto label_149114;
            case 0x149120u: goto label_149120;
            case 0x14918Cu: goto label_14918c;
            case 0x1491B4u: goto label_1491b4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x149134u;
    // 0x149134: 0x0  nop
    ctx->pc = 0x149134u;
    // NOP
    // 0x149138: 0x3c050024  lui         $a1, 0x24
    ctx->pc = 0x149138u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)36 << 16));
    // 0x14913c: 0x805221c  j           func_148870
    ctx->pc = 0x14913Cu;
    ctx->pc = 0x149140u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x14913Cu;
            // 0x149140: 0x24a5e1a8  addiu       $a1, $a1, -0x1E58 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294959528));
        ctx->in_delay_slot = false;
    ctx->pc = 0x148870u;
    if (runtime->hasFunction(0x148870u)) {
        auto targetFn = runtime->lookupFunction(0x148870u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00148870_0x148870(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x149144u;
    // 0x149144: 0x0  nop
    ctx->pc = 0x149144u;
    // NOP
    // 0x149148: 0x3c050024  lui         $a1, 0x24
    ctx->pc = 0x149148u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)36 << 16));
    // 0x14914c: 0x805221c  j           func_148870
    ctx->pc = 0x14914Cu;
    ctx->pc = 0x149150u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x14914Cu;
            // 0x149150: 0x24a5e1d8  addiu       $a1, $a1, -0x1E28 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294959576));
        ctx->in_delay_slot = false;
    ctx->pc = 0x148870u;
    if (runtime->hasFunction(0x148870u)) {
        auto targetFn = runtime->lookupFunction(0x148870u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00148870_0x148870(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x149154u;
    // 0x149154: 0x0  nop
    ctx->pc = 0x149154u;
    // NOP
    // 0x149158: 0x3c050024  lui         $a1, 0x24
    ctx->pc = 0x149158u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)36 << 16));
    // 0x14915c: 0x805221c  j           func_148870
    ctx->pc = 0x14915Cu;
    ctx->pc = 0x149160u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x14915Cu;
            // 0x149160: 0x24a5e1f0  addiu       $a1, $a1, -0x1E10 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294959600));
        ctx->in_delay_slot = false;
    ctx->pc = 0x148870u;
    if (runtime->hasFunction(0x148870u)) {
        auto targetFn = runtime->lookupFunction(0x148870u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00148870_0x148870(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x149164u;
    // 0x149164: 0x0  nop
    ctx->pc = 0x149164u;
    // NOP
    // 0x149168: 0x3c050024  lui         $a1, 0x24
    ctx->pc = 0x149168u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)36 << 16));
    // 0x14916c: 0x805221c  j           func_148870
    ctx->pc = 0x14916Cu;
    ctx->pc = 0x149170u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x14916Cu;
            // 0x149170: 0x24a5e228  addiu       $a1, $a1, -0x1DD8 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294959656));
        ctx->in_delay_slot = false;
    ctx->pc = 0x148870u;
    if (runtime->hasFunction(0x148870u)) {
        auto targetFn = runtime->lookupFunction(0x148870u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00148870_0x148870(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x149174u;
    // 0x149174: 0x0  nop
    ctx->pc = 0x149174u;
    // NOP
    // 0x149178: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x149178u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x14917c: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x14917cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x149180: 0x8c840040  lw          $a0, 0x40($a0)
    ctx->pc = 0x149180u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 64)));
    // 0x149184: 0xc044f26  jal         func_113C98
    ctx->pc = 0x149184u;
    SET_GPR_U32(ctx, 31, 0x14918Cu);
    ctx->pc = 0x149188u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x149184u;
            // 0x149188: 0x24840068  addiu       $a0, $a0, 0x68 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 104));
        ctx->in_delay_slot = false;
    ctx->pc = 0x113C98u;
    if (runtime->hasFunction(0x113C98u)) {
        auto targetFn = runtime->lookupFunction(0x113C98u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14918Cu; }
        if (ctx->pc != 0x14918Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00113C98_0x113c98(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14918Cu; }
        if (ctx->pc != 0x14918Cu) { return; }
    }
    ctx->pc = 0x14918Cu;
label_14918c:
    // 0x14918c: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x14918cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x149190: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x149190u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x149194: 0x3e00008  jr          $ra
    ctx->pc = 0x149194u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x149198u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x149194u;
            // 0x149198: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x148ECCu: goto label_148ecc;
            case 0x148ED4u: goto label_148ed4;
            case 0x148EE8u: goto label_148ee8;
            case 0x148EF0u: goto label_148ef0;
            case 0x148F38u: goto label_148f38;
            case 0x148F3Cu: goto label_148f3c;
            case 0x148F44u: goto label_148f44;
            case 0x148F4Cu: goto label_148f4c;
            case 0x148F60u: goto label_148f60;
            case 0x148FACu: goto label_148fac;
            case 0x148FB8u: goto label_148fb8;
            case 0x148FF4u: goto label_148ff4;
            case 0x149010u: goto label_149010;
            case 0x14903Cu: goto label_14903c;
            case 0x1490C0u: goto label_1490c0;
            case 0x1490CCu: goto label_1490cc;
            case 0x1490DCu: goto label_1490dc;
            case 0x1490E8u: goto label_1490e8;
            case 0x1490F4u: goto label_1490f4;
            case 0x1490F8u: goto label_1490f8;
            case 0x149104u: goto label_149104;
            case 0x149114u: goto label_149114;
            case 0x149120u: goto label_149120;
            case 0x14918Cu: goto label_14918c;
            case 0x1491B4u: goto label_1491b4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x14919Cu;
    // 0x14919c: 0x0  nop
    ctx->pc = 0x14919cu;
    // NOP
    // 0x1491a0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1491a0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1491a4: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1491a4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1491a8: 0x8c840040  lw          $a0, 0x40($a0)
    ctx->pc = 0x1491a8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 64)));
    // 0x1491ac: 0xc044f60  jal         func_113D80
    ctx->pc = 0x1491ACu;
    SET_GPR_U32(ctx, 31, 0x1491B4u);
    ctx->pc = 0x1491B0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1491ACu;
            // 0x1491b0: 0x24840068  addiu       $a0, $a0, 0x68 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 104));
        ctx->in_delay_slot = false;
    ctx->pc = 0x113D80u;
    if (runtime->hasFunction(0x113D80u)) {
        auto targetFn = runtime->lookupFunction(0x113D80u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1491B4u; }
        if (ctx->pc != 0x1491B4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00113D80_0x113d80(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1491B4u; }
        if (ctx->pc != 0x1491B4u) { return; }
    }
    ctx->pc = 0x1491B4u;
label_1491b4:
    // 0x1491b4: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1491b4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1491b8: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1491b8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1491bc: 0x3e00008  jr          $ra
    ctx->pc = 0x1491BCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1491C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1491BCu;
            // 0x1491c0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x148ECCu: goto label_148ecc;
            case 0x148ED4u: goto label_148ed4;
            case 0x148EE8u: goto label_148ee8;
            case 0x148EF0u: goto label_148ef0;
            case 0x148F38u: goto label_148f38;
            case 0x148F3Cu: goto label_148f3c;
            case 0x148F44u: goto label_148f44;
            case 0x148F4Cu: goto label_148f4c;
            case 0x148F60u: goto label_148f60;
            case 0x148FACu: goto label_148fac;
            case 0x148FB8u: goto label_148fb8;
            case 0x148FF4u: goto label_148ff4;
            case 0x149010u: goto label_149010;
            case 0x14903Cu: goto label_14903c;
            case 0x1490C0u: goto label_1490c0;
            case 0x1490CCu: goto label_1490cc;
            case 0x1490DCu: goto label_1490dc;
            case 0x1490E8u: goto label_1490e8;
            case 0x1490F4u: goto label_1490f4;
            case 0x1490F8u: goto label_1490f8;
            case 0x149104u: goto label_149104;
            case 0x149114u: goto label_149114;
            case 0x149120u: goto label_149120;
            case 0x14918Cu: goto label_14918c;
            case 0x1491B4u: goto label_1491b4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1491C4u;
    // 0x1491c4: 0x0  nop
    ctx->pc = 0x1491c4u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
