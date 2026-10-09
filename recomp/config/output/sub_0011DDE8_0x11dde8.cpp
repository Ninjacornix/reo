#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0011DDE8
// Address: 0x11dde8 - 0x11df30
void sub_0011DDE8_0x11dde8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0011DDE8_0x11dde8");
#endif

    switch (ctx->pc) {
        case 0x11de30u: goto label_11de30;
        case 0x11de48u: goto label_11de48;
        case 0x11de60u: goto label_11de60;
        case 0x11de68u: goto label_11de68;
        case 0x11de70u: goto label_11de70;
        case 0x11de7cu: goto label_11de7c;
        case 0x11de80u: goto label_11de80;
        case 0x11de88u: goto label_11de88;
        case 0x11de98u: goto label_11de98;
        case 0x11ded8u: goto label_11ded8;
        default: break;
    }

    ctx->pc = 0x11dde8u;

    // 0x11dde8: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x11dde8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x11ddec: 0x3c021000  lui         $v0, 0x1000
    ctx->pc = 0x11ddecu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)4096 << 16));
    // 0x11ddf0: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x11ddf0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x11ddf4: 0x34421810  ori         $v0, $v0, 0x1810
    ctx->pc = 0x11ddf4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)6160);
    // 0x11ddf8: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x11ddf8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x11ddfc: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x11ddfcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x11de00: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x11de00u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x11de04: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x11de04u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x11de08: 0x30630100  andi        $v1, $v1, 0x100
    ctx->pc = 0x11de08u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)256);
    // 0x11de0c: 0x14600026  bnez        $v1, . + 4 + (0x26 << 2)
    ctx->pc = 0x11DE0Cu;
    {
        const bool branch_taken_0x11de0c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x11DE10u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11DE0Cu;
            // 0x11de10: 0xdfbf0030  ld          $ra, 0x30($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11de0c) {
            ctx->pc = 0x11DEA8u;
            goto label_11dea8;
        }
    }
    ctx->pc = 0x11DE14u;
    // 0x11de14: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x11de14u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x11de18: 0x24120002  addiu       $s2, $zero, 0x2
    ctx->pc = 0x11de18u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x11de1c: 0x2450b3a8  addiu       $s0, $v0, -0x4C58
    ctx->pc = 0x11de1cu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), 4294947752));
    // 0x11de20: 0x8c44b3a8  lw          $a0, -0x4C58($v0)
    ctx->pc = 0x11de20u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294947752)));
    // 0x11de24: 0x8e050004  lw          $a1, 0x4($s0)
    ctx->pc = 0x11de24u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x11de28: 0xc047760  jal         func_11DD80
    ctx->pc = 0x11DE28u;
    SET_GPR_U32(ctx, 31, 0x11DE30u);
    ctx->pc = 0x11DE2Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11DE28u;
            // 0x11de2c: 0x26110010  addiu       $s1, $s0, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 16), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11DD80u;
    if (runtime->hasFunction(0x11DD80u)) {
        auto targetFn = runtime->lookupFunction(0x11DD80u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11DE30u; }
        if (ctx->pc != 0x11DE30u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011DD80_0x11dd80(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11DE30u; }
        if (ctx->pc != 0x11DE30u) { return; }
    }
    ctx->pc = 0x11DE30u;
label_11de30:
    // 0x11de30: 0x3c050021  lui         $a1, 0x21
    ctx->pc = 0x11de30u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)33 << 16));
    // 0x11de34: 0x3c048007  lui         $a0, 0x8007
    ctx->pc = 0x11de34u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)32775 << 16));
    // 0x11de38: 0x24a5ac40  addiu       $a1, $a1, -0x53C0
    ctx->pc = 0x11de38u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294945856));
    // 0x11de3c: 0x34846000  ori         $a0, $a0, 0x6000
    ctx->pc = 0x11de3cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)24576);
    // 0x11de40: 0xc047764  jal         func_11DD90
    ctx->pc = 0x11DE40u;
    SET_GPR_U32(ctx, 31, 0x11DE48u);
    ctx->pc = 0x11DE44u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11DE40u;
            // 0x11de44: 0x24060740  addiu       $a2, $zero, 0x740 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1856));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11DD90u;
    if (runtime->hasFunction(0x11DD90u)) {
        auto targetFn = runtime->lookupFunction(0x11DD90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11DE48u; }
        if (ctx->pc != 0x11DE48u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011DD90_0x11dd90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11DE48u; }
        if (ctx->pc != 0x11DE48u) { return; }
    }
    ctx->pc = 0x11DE48u;
label_11de48:
    // 0x11de48: 0x3c050021  lui         $a1, 0x21
    ctx->pc = 0x11de48u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)33 << 16));
    // 0x11de4c: 0x3c040008  lui         $a0, 0x8
    ctx->pc = 0x11de4cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)8 << 16));
    // 0x11de50: 0x24a5b380  addiu       $a1, $a1, -0x4C80
    ctx->pc = 0x11de50u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294947712));
    // 0x11de54: 0x34842000  ori         $a0, $a0, 0x2000
    ctx->pc = 0x11de54u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)8192);
    // 0x11de58: 0xc047764  jal         func_11DD90
    ctx->pc = 0x11DE58u;
    SET_GPR_U32(ctx, 31, 0x11DE60u);
    ctx->pc = 0x11DE5Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11DE58u;
            // 0x11de5c: 0x24060028  addiu       $a2, $zero, 0x28 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 40));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11DD90u;
    if (runtime->hasFunction(0x11DD90u)) {
        auto targetFn = runtime->lookupFunction(0x11DD90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11DE60u; }
        if (ctx->pc != 0x11DE60u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011DD90_0x11dd90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11DE60u; }
        if (ctx->pc != 0x11DE60u) { return; }
    }
    ctx->pc = 0x11DE60u;
label_11de60:
    // 0x11de60: 0xc045228  jal         func_1148A0
    ctx->pc = 0x11DE60u;
    SET_GPR_U32(ctx, 31, 0x11DE68u);
    ctx->pc = 0x11DE64u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11DE60u;
            // 0x11de64: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1148A0u;
    if (runtime->hasFunction(0x1148A0u)) {
        auto targetFn = runtime->lookupFunction(0x1148A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11DE68u; }
        if (ctx->pc != 0x11DE68u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001148A0_0x1148a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11DE68u; }
        if (ctx->pc != 0x11DE68u) { return; }
    }
    ctx->pc = 0x11DE68u;
label_11de68:
    // 0x11de68: 0xc045228  jal         func_1148A0
    ctx->pc = 0x11DE68u;
    SET_GPR_U32(ctx, 31, 0x11DE70u);
    ctx->pc = 0x11DE6Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11DE68u;
            // 0x11de6c: 0x24040002  addiu       $a0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1148A0u;
    if (runtime->hasFunction(0x1148A0u)) {
        auto targetFn = runtime->lookupFunction(0x1148A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11DE70u; }
        if (ctx->pc != 0x11DE70u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001148A0_0x1148a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11DE70u; }
        if (ctx->pc != 0x11DE70u) { return; }
    }
    ctx->pc = 0x11DE70u;
label_11de70:
    // 0x11de70: 0x8e040008  lw          $a0, 0x8($s0)
    ctx->pc = 0x11de70u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x11de74: 0xc047760  jal         func_11DD80
    ctx->pc = 0x11DE74u;
    SET_GPR_U32(ctx, 31, 0x11DE7Cu);
    ctx->pc = 0x11DE78u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11DE74u;
            // 0x11de78: 0x8e05000c  lw          $a1, 0xC($s0) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11DD80u;
    if (runtime->hasFunction(0x11DD80u)) {
        auto targetFn = runtime->lookupFunction(0x11DD80u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11DE7Cu; }
        if (ctx->pc != 0x11DE7Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011DD80_0x11dd80(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11DE7Cu; }
        if (ctx->pc != 0x11DE7Cu) { return; }
    }
    ctx->pc = 0x11DE7Cu;
label_11de7c:
    // 0x11de7c: 0x8e240000  lw          $a0, 0x0($s1)
    ctx->pc = 0x11de7cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
label_11de80:
    // 0x11de80: 0xc047776  jal         func_11DDD8
    ctx->pc = 0x11DE80u;
    SET_GPR_U32(ctx, 31, 0x11DE88u);
    ctx->pc = 0x11DE84u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11DE80u;
            // 0x11de84: 0x26520001  addiu       $s2, $s2, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11DDD8u;
    if (runtime->hasFunction(0x11DDD8u)) {
        auto targetFn = runtime->lookupFunction(0x11DDD8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11DE88u; }
        if (ctx->pc != 0x11DE88u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011DDD8_0x11ddd8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11DE88u; }
        if (ctx->pc != 0x11DE88u) { return; }
    }
    ctx->pc = 0x11DE88u;
label_11de88:
    // 0x11de88: 0x8e240000  lw          $a0, 0x0($s1)
    ctx->pc = 0x11de88u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x11de8c: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x11de8cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11de90: 0xc047760  jal         func_11DD80
    ctx->pc = 0x11DE90u;
    SET_GPR_U32(ctx, 31, 0x11DE98u);
    ctx->pc = 0x11DE94u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11DE90u;
            // 0x11de94: 0x26310008  addiu       $s1, $s1, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 8));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11DD80u;
    if (runtime->hasFunction(0x11DD80u)) {
        auto targetFn = runtime->lookupFunction(0x11DD80u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11DE98u; }
        if (ctx->pc != 0x11DE98u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011DD80_0x11dd80(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11DE98u; }
        if (ctx->pc != 0x11DE98u) { return; }
    }
    ctx->pc = 0x11DE98u;
label_11de98:
    // 0x11de98: 0x2e420008  sltiu       $v0, $s2, 0x8
    ctx->pc = 0x11de98u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 18) < (uint64_t)(int64_t)(int32_t)8) ? 1 : 0);
    // 0x11de9c: 0x5440fff8  bnel        $v0, $zero, . + 4 + (-0x8 << 2)
    ctx->pc = 0x11DE9Cu;
    {
        const bool branch_taken_0x11de9c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x11de9c) {
            ctx->pc = 0x11DEA0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x11DE9Cu;
            // 0x11dea0: 0x8e240000  lw          $a0, 0x0($s1) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x11DE80u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_11de80;
        }
    }
    ctx->pc = 0x11DEA4u;
    // 0x11dea4: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x11dea4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
label_11dea8:
    // 0x11dea8: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x11dea8u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x11deac: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x11deacu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x11deb0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x11deb0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x11deb4: 0x3e00008  jr          $ra
    ctx->pc = 0x11DEB4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11DEB8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11DEB4u;
            // 0x11deb8: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11DE30u: goto label_11de30;
            case 0x11DE48u: goto label_11de48;
            case 0x11DE60u: goto label_11de60;
            case 0x11DE68u: goto label_11de68;
            case 0x11DE70u: goto label_11de70;
            case 0x11DE7Cu: goto label_11de7c;
            case 0x11DE80u: goto label_11de80;
            case 0x11DE88u: goto label_11de88;
            case 0x11DE98u: goto label_11de98;
            case 0x11DEA8u: goto label_11dea8;
            case 0x11DED8u: goto label_11ded8;
            case 0x11DEFCu: goto label_11defc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11DEBCu;
    // 0x11debc: 0x0  nop
    ctx->pc = 0x11debcu;
    // NOP
    // 0x11dec0: 0x40036000  mfc0        $v1, Status
    ctx->pc = 0x11dec0u;
    SET_GPR_S32(ctx, 3, (int32_t)ctx->cop0_status);
    // 0x11dec4: 0x3c020001  lui         $v0, 0x1
    ctx->pc = 0x11dec4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)1 << 16));
    // 0x11dec8: 0x621824  and         $v1, $v1, $v0
    ctx->pc = 0x11dec8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x11decc: 0x1060000b  beqz        $v1, . + 4 + (0xB << 2)
    ctx->pc = 0x11DECCu;
    {
        const bool branch_taken_0x11decc = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x11DED0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11DECCu;
            // 0x11ded0: 0x3c060001  lui         $a2, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)1 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11decc) {
            ctx->pc = 0x11DEFCu;
            goto label_11defc;
        }
    }
    ctx->pc = 0x11DED4u;
    // 0x11ded4: 0x0  nop
    ctx->pc = 0x11ded4u;
    // NOP
label_11ded8:
    // 0x11ded8: 0x42000039  di
    ctx->pc = 0x11ded8u;
    ctx->cop0_status &= ~0x10000; // Disable interrupts
    // 0x11dedc: 0x40f  sync.p
    ctx->pc = 0x11dedcu;
    // SYNC instruction - memory barrier
// In recompiled code, we don't need explicit memory barriers
    // 0x11dee0: 0x40026000  mfc0        $v0, Status
    ctx->pc = 0x11dee0u;
    SET_GPR_S32(ctx, 2, (int32_t)ctx->cop0_status);
    // 0x11dee4: 0x461024  and         $v0, $v0, $a2
    ctx->pc = 0x11dee4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 6));
    // 0x11dee8: 0x0  nop
    ctx->pc = 0x11dee8u;
    // NOP
    // 0x11deec: 0x0  nop
    ctx->pc = 0x11deecu;
    // NOP
    // 0x11def0: 0x0  nop
    ctx->pc = 0x11def0u;
    // NOP
    // 0x11def4: 0x1440fff8  bnez        $v0, . + 4 + (-0x8 << 2)
    ctx->pc = 0x11DEF4u;
    {
        const bool branch_taken_0x11def4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x11def4) {
            ctx->pc = 0x11DED8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_11ded8;
        }
    }
    ctx->pc = 0x11DEFCu;
label_11defc:
    // 0x11defc: 0x40026000  mfc0        $v0, Status
    ctx->pc = 0x11defcu;
    SET_GPR_S32(ctx, 2, (int32_t)ctx->cop0_status);
    // 0x11df00: 0x40f  sync.p
    ctx->pc = 0x11df00u;
    // SYNC instruction - memory barrier
// In recompiled code, we don't need explicit memory barriers
    // 0x11df04: 0x34420006  ori         $v0, $v0, 0x6
    ctx->pc = 0x11df04u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)6);
    // 0x11df08: 0x38420002  xori        $v0, $v0, 0x2
    ctx->pc = 0x11df08u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) ^ (uint64_t)(uint16_t)2);
    // 0x11df0c: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x11df0cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x11df10: 0x40826000  mtc0        $v0, Status
    ctx->pc = 0x11df10u;
    ctx->cop0_status = GPR_U32(ctx, 2) & 0xFF57FFFF;
    // 0x11df14: 0x40f  sync.p
    ctx->pc = 0x11df14u;
    // SYNC instruction - memory barrier
// In recompiled code, we don't need explicit memory barriers
    // 0x11df18: 0xac850000  sw          $a1, 0x0($a0)
    ctx->pc = 0x11df18u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 5));
    // 0x11df1c: 0x409ff000  mtc0        $ra, ErrorEPC
    ctx->pc = 0x11df1cu;
    ctx->cop0_errorepc = GPR_U32(ctx, 31);
    // 0x11df20: 0x40f  sync.p
    ctx->pc = 0x11df20u;
    // SYNC instruction - memory barrier
// In recompiled code, we don't need explicit memory barriers
    // 0x11df24: 0x42000018  eret
    ctx->pc = 0x11df24u;
    if (ctx->cop0_status & 0x4) { 
    ctx->pc = ctx->cop0_errorepc; 
    ctx->cop0_status &= ~0x4; 
} else { 
    ctx->pc = ctx->cop0_epc; 
    ctx->cop0_status &= ~0x2; 
} 
runtime->clearLLBit(ctx); 
return;
    // 0x11df28: 0x3e00008  jr          $ra
    ctx->pc = 0x11DF28u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11DE30u: goto label_11de30;
            case 0x11DE48u: goto label_11de48;
            case 0x11DE60u: goto label_11de60;
            case 0x11DE68u: goto label_11de68;
            case 0x11DE70u: goto label_11de70;
            case 0x11DE7Cu: goto label_11de7c;
            case 0x11DE80u: goto label_11de80;
            case 0x11DE88u: goto label_11de88;
            case 0x11DE98u: goto label_11de98;
            case 0x11DEA8u: goto label_11dea8;
            case 0x11DED8u: goto label_11ded8;
            case 0x11DEFCu: goto label_11defc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11DF30u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
