#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00138E58
// Address: 0x138e58 - 0x138f78
void sub_00138E58_0x138e58(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00138E58_0x138e58");
#endif

    switch (ctx->pc) {
        case 0x138e98u: goto label_138e98;
        case 0x138ee0u: goto label_138ee0;
        case 0x138f14u: goto label_138f14;
        default: break;
    }

    ctx->pc = 0x138e58u;

    // 0x138e58: 0x3c070026  lui         $a3, 0x26
    ctx->pc = 0x138e58u;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)38 << 16));
    // 0x138e5c: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x138e5cu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x138e60: 0x24e723c0  addiu       $a3, $a3, 0x23C0
    ctx->pc = 0x138e60u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 9152));
    // 0x138e64: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x138e64u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x138e68: 0x3c020022  lui         $v0, 0x22
    ctx->pc = 0x138e68u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)34 << 16));
    // 0x138e6c: 0x3c090026  lui         $t1, 0x26
    ctx->pc = 0x138e6cu;
    SET_GPR_S32(ctx, 9, (int32_t)((uint32_t)38 << 16));
    // 0x138e70: 0xace40000  sw          $a0, 0x0($a3)
    ctx->pc = 0x138e70u;
    WRITE32(ADD32(GPR_U32(ctx, 7), 0), GPR_U32(ctx, 4));
    // 0x138e74: 0x2444c870  addiu       $a0, $v0, -0x3790
    ctx->pc = 0x138e74u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), 4294953072));
    // 0x138e78: 0x252924c0  addiu       $t1, $t1, 0x24C0
    ctx->pc = 0x138e78u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 9408));
    // 0x138e7c: 0x24050003  addiu       $a1, $zero, 0x3
    ctx->pc = 0x138e7cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x138e80: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x138e80u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x138e84: 0x24080004  addiu       $t0, $zero, 0x4
    ctx->pc = 0x138e84u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x138e88: 0x502d  daddu       $t2, $zero, $zero
    ctx->pc = 0x138e88u;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x138e8c: 0x582d  daddu       $t3, $zero, $zero
    ctx->pc = 0x138e8cu;
    SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x138e90: 0xc045e7a  jal         func_1179E8
    ctx->pc = 0x138E90u;
    SET_GPR_U32(ctx, 31, 0x138E98u);
    ctx->pc = 0x138E94u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x138E90u;
            // 0x138e94: 0xafa00000  sw          $zero, 0x0($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1179E8u;
    if (runtime->hasFunction(0x1179E8u)) {
        auto targetFn = runtime->lookupFunction(0x1179E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x138E98u; }
        if (ctx->pc != 0x138E98u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001179E8_0x1179e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x138E98u; }
        if (ctx->pc != 0x138E98u) { return; }
    }
    ctx->pc = 0x138E98u;
label_138e98:
    // 0x138e98: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x138e98u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x138e9c: 0x3e00008  jr          $ra
    ctx->pc = 0x138E9Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x138EA0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x138E9Cu;
            // 0x138ea0: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x138E98u: goto label_138e98;
            case 0x138EE0u: goto label_138ee0;
            case 0x138EFCu: goto label_138efc;
            case 0x138F14u: goto label_138f14;
            case 0x138F54u: goto label_138f54;
            default: break;
        }
        return;
    }
    ctx->pc = 0x138EA4u;
    // 0x138ea4: 0x0  nop
    ctx->pc = 0x138ea4u;
    // NOP
    // 0x138ea8: 0x3c030022  lui         $v1, 0x22
    ctx->pc = 0x138ea8u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)34 << 16));
    // 0x138eac: 0x2463c420  addiu       $v1, $v1, -0x3BE0
    ctx->pc = 0x138eacu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294951968));
    // 0x138eb0: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x138eb0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x138eb4: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x138eb4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x138eb8: 0x3e00008  jr          $ra
    ctx->pc = 0x138EB8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x138EBCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x138EB8u;
            // 0x138ebc: 0xac620000  sw          $v0, 0x0($v1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x138E98u: goto label_138e98;
            case 0x138EE0u: goto label_138ee0;
            case 0x138EFCu: goto label_138efc;
            case 0x138F14u: goto label_138f14;
            case 0x138F54u: goto label_138f54;
            default: break;
        }
        return;
    }
    ctx->pc = 0x138EC0u;
    // 0x138ec0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x138ec0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x138ec4: 0xa0202d  daddu       $a0, $a1, $zero
    ctx->pc = 0x138ec4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x138ec8: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x138ec8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x138ecc: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x138eccu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x138ed0: 0x18c0000a  blez        $a2, . + 4 + (0xA << 2)
    ctx->pc = 0x138ED0u;
    {
        const bool branch_taken_0x138ed0 = (GPR_S64(ctx, 6) <= 0);
        ctx->pc = 0x138ED4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x138ED0u;
            // 0x138ed4: 0xffbf0008  sd          $ra, 0x8($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x138ed0) {
            ctx->pc = 0x138EFCu;
            goto label_138efc;
        }
    }
    ctx->pc = 0x138ED8u;
    // 0x138ed8: 0x2407ffaa  addiu       $a3, $zero, -0x56
    ctx->pc = 0x138ed8u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967210));
    // 0x138edc: 0x0  nop
    ctx->pc = 0x138edcu;
    // NOP
label_138ee0:
    // 0x138ee0: 0x851821  addu        $v1, $a0, $a1
    ctx->pc = 0x138ee0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 5)));
    // 0x138ee4: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x138ee4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x138ee8: 0xa6102a  slt         $v0, $a1, $a2
    ctx->pc = 0x138ee8u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)GPR_S64(ctx, 6)) ? 1 : 0);
    // 0x138eec: 0x0  nop
    ctx->pc = 0x138eecu;
    // NOP
    // 0x138ef0: 0x0  nop
    ctx->pc = 0x138ef0u;
    // NOP
    // 0x138ef4: 0x1440fffa  bnez        $v0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x138EF4u;
    {
        const bool branch_taken_0x138ef4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x138EF8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x138EF4u;
            // 0x138ef8: 0xa0670000  sb          $a3, 0x0($v1) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 7));
        ctx->in_delay_slot = false;
        if (branch_taken_0x138ef4) {
            ctx->pc = 0x138EE0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_138ee0;
        }
    }
    ctx->pc = 0x138EFCu;
label_138efc:
    // 0x138efc: 0x3c100022  lui         $s0, 0x22
    ctx->pc = 0x138efcu;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)34 << 16));
    // 0x138f00: 0x3c050024  lui         $a1, 0x24
    ctx->pc = 0x138f00u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)36 << 16));
    // 0x138f04: 0x2610c424  addiu       $s0, $s0, -0x3BDC
    ctx->pc = 0x138f04u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4294951972));
    // 0x138f08: 0x24a5c950  addiu       $a1, $a1, -0x36B0
    ctx->pc = 0x138f08u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294953296));
    // 0x138f0c: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x138F0Cu;
    SET_GPR_U32(ctx, 31, 0x138F14u);
    ctx->pc = 0x138F10u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x138F0Cu;
            // 0x138f10: 0x8e060000  lw          $a2, 0x0($s0) (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x138F14u; }
        if (ctx->pc != 0x138F14u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x138F14u; }
        if (ctx->pc != 0x138F14u) { return; }
    }
    ctx->pc = 0x138F14u;
label_138f14:
    // 0x138f14: 0x8e030000  lw          $v1, 0x0($s0)
    ctx->pc = 0x138f14u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x138f18: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x138f18u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x138f1c: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x138f1cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x138f20: 0xae030000  sw          $v1, 0x0($s0)
    ctx->pc = 0x138f20u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 3));
    // 0x138f24: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x138f24u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x138f28: 0x3e00008  jr          $ra
    ctx->pc = 0x138F28u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x138F2Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x138F28u;
            // 0x138f2c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x138E98u: goto label_138e98;
            case 0x138EE0u: goto label_138ee0;
            case 0x138EFCu: goto label_138efc;
            case 0x138F14u: goto label_138f14;
            case 0x138F54u: goto label_138f54;
            default: break;
        }
        return;
    }
    ctx->pc = 0x138F30u;
    // 0x138f30: 0x41900  sll         $v1, $a0, 4
    ctx->pc = 0x138f30u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 4));
    // 0x138f34: 0x2c850008  sltiu       $a1, $a0, 0x8
    ctx->pc = 0x138f34u;
    SET_GPR_U64(ctx, 5, ((uint64_t)GPR_U64(ctx, 4) < (uint64_t)(int64_t)(int32_t)8) ? 1 : 0);
    // 0x138f38: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x138f38u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x138f3c: 0x10a00005  beqz        $a1, . + 4 + (0x5 << 2)
    ctx->pc = 0x138F3Cu;
    {
        const bool branch_taken_0x138f3c = (GPR_U64(ctx, 5) == GPR_U64(ctx, 0));
        ctx->pc = 0x138F40u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x138F3Cu;
            // 0x138f40: 0x641821  addu        $v1, $v1, $a0 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x138f3c) {
            ctx->pc = 0x138F54u;
            goto label_138f54;
        }
    }
    ctx->pc = 0x138F44u;
    // 0x138f44: 0x31080  sll         $v0, $v1, 2
    ctx->pc = 0x138f44u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x138f48: 0x3c010022  lui         $at, 0x22
    ctx->pc = 0x138f48u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)34 << 16));
    // 0x138f4c: 0x2421c430  addiu       $at, $at, -0x3BD0
    ctx->pc = 0x138f4cu;
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), 4294951984));
    // 0x138f50: 0x221021  addu        $v0, $at, $v0
    ctx->pc = 0x138f50u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 2)));
label_138f54:
    // 0x138f54: 0x3e00008  jr          $ra
    ctx->pc = 0x138F54u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x138E98u: goto label_138e98;
            case 0x138EE0u: goto label_138ee0;
            case 0x138EFCu: goto label_138efc;
            case 0x138F14u: goto label_138f14;
            case 0x138F54u: goto label_138f54;
            default: break;
        }
        return;
    }
    ctx->pc = 0x138F5Cu;
    // 0x138f5c: 0x0  nop
    ctx->pc = 0x138f5cu;
    // NOP
    // 0x138f60: 0xac80002c  sw          $zero, 0x2C($a0)
    ctx->pc = 0x138f60u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 44), GPR_U32(ctx, 0));
    // 0x138f64: 0xac800020  sw          $zero, 0x20($a0)
    ctx->pc = 0x138f64u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 32), GPR_U32(ctx, 0));
    // 0x138f68: 0xac800024  sw          $zero, 0x24($a0)
    ctx->pc = 0x138f68u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 36), GPR_U32(ctx, 0));
    // 0x138f6c: 0x3e00008  jr          $ra
    ctx->pc = 0x138F6Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x138F70u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x138F6Cu;
            // 0x138f70: 0xac800028  sw          $zero, 0x28($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 40), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x138E98u: goto label_138e98;
            case 0x138EE0u: goto label_138ee0;
            case 0x138EFCu: goto label_138efc;
            case 0x138F14u: goto label_138f14;
            case 0x138F54u: goto label_138f54;
            default: break;
        }
        return;
    }
    ctx->pc = 0x138F74u;
    // 0x138f74: 0x0  nop
    ctx->pc = 0x138f74u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
