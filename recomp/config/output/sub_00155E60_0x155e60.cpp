#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00155E60
// Address: 0x155e60 - 0x1560f0
void sub_00155E60_0x155e60(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00155E60_0x155e60");
#endif

    switch (ctx->pc) {
        case 0x155e78u: goto label_155e78;
        case 0x155e90u: goto label_155e90;
        case 0x155ea8u: goto label_155ea8;
        case 0x155f30u: goto label_155f30;
        case 0x155f58u: goto label_155f58;
        default: break;
    }

    ctx->pc = 0x155e60u;

label_155e60:
    // 0x155e60: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x155e60u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x155e64: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x155e64u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x155e68: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x155e68u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x155e6c: 0x8041eac  j           func_107AB0
    ctx->pc = 0x155E6Cu;
    ctx->pc = 0x155E70u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x155E6Cu;
            // 0x155e70: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00107AB0_0x107ab0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x155E74u;
    // 0x155e74: 0x0  nop
    ctx->pc = 0x155e74u;
    // NOP
label_155e78:
    // 0x155e78: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x155e78u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x155e7c: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x155e7cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x155e80: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x155e80u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x155e84: 0x8041eac  j           func_107AB0
    ctx->pc = 0x155E84u;
    ctx->pc = 0x155E88u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x155E84u;
            // 0x155e88: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00107AB0_0x107ab0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x155E8Cu;
    // 0x155e8c: 0x0  nop
    ctx->pc = 0x155e8cu;
    // NOP
label_155e90:
    // 0x155e90: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x155e90u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x155e94: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x155e94u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x155e98: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x155e98u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x155e9c: 0x8041eac  j           func_107AB0
    ctx->pc = 0x155E9Cu;
    ctx->pc = 0x155EA0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x155E9Cu;
            // 0x155ea0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00107AB0_0x107ab0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x155EA4u;
    // 0x155ea4: 0x0  nop
    ctx->pc = 0x155ea4u;
    // NOP
label_155ea8:
    // 0x155ea8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x155ea8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x155eac: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x155eacu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x155eb0: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x155eb0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x155eb4: 0x8041eac  j           func_107AB0
    ctx->pc = 0x155EB4u;
    ctx->pc = 0x155EB8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x155EB4u;
            // 0x155eb8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00107AB0_0x107ab0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x155EBCu;
    // 0x155ebc: 0x0  nop
    ctx->pc = 0x155ebcu;
    // NOP
    // 0x155ec0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x155ec0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x155ec4: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x155ec4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x155ec8: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x155ec8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x155ecc: 0x8055798  j           func_155E60
    ctx->pc = 0x155ECCu;
    ctx->pc = 0x155ED0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x155ECCu;
            // 0x155ed0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x155E60u;
    if (runtime->shouldPreemptGuestExecution()) {
        return;
    }
    goto label_155e60;
    ctx->pc = 0x155ED4u;
    // 0x155ed4: 0x0  nop
    ctx->pc = 0x155ed4u;
    // NOP
    // 0x155ed8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x155ed8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x155edc: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x155edcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x155ee0: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x155ee0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x155ee4: 0x805579e  j           func_155E78
    ctx->pc = 0x155EE4u;
    ctx->pc = 0x155EE8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x155EE4u;
            // 0x155ee8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x155E78u;
    if (runtime->shouldPreemptGuestExecution()) {
        return;
    }
    goto label_155e78;
    ctx->pc = 0x155EECu;
    // 0x155eec: 0x0  nop
    ctx->pc = 0x155eecu;
    // NOP
    // 0x155ef0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x155ef0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x155ef4: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x155ef4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x155ef8: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x155ef8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x155efc: 0x80557a4  j           func_155E90
    ctx->pc = 0x155EFCu;
    ctx->pc = 0x155F00u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x155EFCu;
            // 0x155f00: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x155E90u;
    if (runtime->shouldPreemptGuestExecution()) {
        return;
    }
    goto label_155e90;
    ctx->pc = 0x155F04u;
    // 0x155f04: 0x0  nop
    ctx->pc = 0x155f04u;
    // NOP
    // 0x155f08: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x155f08u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x155f0c: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x155f0cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x155f10: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x155f10u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x155f14: 0x80557aa  j           func_155EA8
    ctx->pc = 0x155F14u;
    ctx->pc = 0x155F18u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x155F14u;
            // 0x155f18: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x155EA8u;
    if (runtime->shouldPreemptGuestExecution()) {
        return;
    }
    goto label_155ea8;
    ctx->pc = 0x155F1Cu;
    // 0x155f1c: 0x0  nop
    ctx->pc = 0x155f1cu;
    // NOP
    // 0x155f20: 0x30c3001f  andi        $v1, $a2, 0x1F
    ctx->pc = 0x155f20u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 6) & (uint64_t)(uint16_t)31);
    // 0x155f24: 0x5060000a  beql        $v1, $zero, . + 4 + (0xA << 2)
    ctx->pc = 0x155F24u;
    {
        const bool branch_taken_0x155f24 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x155f24) {
            ctx->pc = 0x155F28u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x155F24u;
            // 0x155f28: 0x63142  srl         $a2, $a2, 5 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)SRL32(GPR_U32(ctx, 6), 5));
        ctx->in_delay_slot = false;
            ctx->pc = 0x155F50u;
            goto label_155f50;
        }
    }
    ctx->pc = 0x155F2Cu;
    // 0x155f2c: 0x0  nop
    ctx->pc = 0x155f2cu;
    // NOP
label_155f30:
    // 0x155f30: 0x90a20000  lbu         $v0, 0x0($a1)
    ctx->pc = 0x155f30u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x155f34: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x155f34u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x155f38: 0x2463ffff  addiu       $v1, $v1, -0x1
    ctx->pc = 0x155f38u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x155f3c: 0xa0820000  sb          $v0, 0x0($a0)
    ctx->pc = 0x155f3cu;
    WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x155f40: 0x0  nop
    ctx->pc = 0x155f40u;
    // NOP
    // 0x155f44: 0x1460fffa  bnez        $v1, . + 4 + (-0x6 << 2)
    ctx->pc = 0x155F44u;
    {
        const bool branch_taken_0x155f44 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x155F48u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x155F44u;
            // 0x155f48: 0x24840001  addiu       $a0, $a0, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x155f44) {
            ctx->pc = 0x155F30u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_155f30;
        }
    }
    ctx->pc = 0x155F4Cu;
    // 0x155f4c: 0x63142  srl         $a2, $a2, 5
    ctx->pc = 0x155f4cu;
    SET_GPR_S32(ctx, 6, (int32_t)SRL32(GPR_U32(ctx, 6), 5));
label_155f50:
    // 0x155f50: 0x10c00065  beqz        $a2, . + 4 + (0x65 << 2)
    ctx->pc = 0x155F50u;
    {
        const bool branch_taken_0x155f50 = (GPR_U64(ctx, 6) == GPR_U64(ctx, 0));
        if (branch_taken_0x155f50) {
            ctx->pc = 0x1560E8u;
            goto label_1560e8;
        }
    }
    ctx->pc = 0x155F58u;
label_155f58:
    // 0x155f58: 0x80a80000  lb          $t0, 0x0($a1)
    ctx->pc = 0x155f58u;
    SET_GPR_S32(ctx, 8, (int8_t)READ8(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x155f5c: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x155f5cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x155f60: 0x80a70000  lb          $a3, 0x0($a1)
    ctx->pc = 0x155f60u;
    SET_GPR_S32(ctx, 7, (int8_t)READ8(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x155f64: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x155f64u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x155f68: 0x80a30000  lb          $v1, 0x0($a1)
    ctx->pc = 0x155f68u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x155f6c: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x155f6cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x155f70: 0x80a20000  lb          $v0, 0x0($a1)
    ctx->pc = 0x155f70u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x155f74: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x155f74u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x155f78: 0xa0880000  sb          $t0, 0x0($a0)
    ctx->pc = 0x155f78u;
    WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 8));
    // 0x155f7c: 0x24c6ffff  addiu       $a2, $a2, -0x1
    ctx->pc = 0x155f7cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294967295));
    // 0x155f80: 0xa0870001  sb          $a3, 0x1($a0)
    ctx->pc = 0x155f80u;
    WRITE8(ADD32(GPR_U32(ctx, 4), 1), (uint8_t)GPR_U32(ctx, 7));
    // 0x155f84: 0xa0830002  sb          $v1, 0x2($a0)
    ctx->pc = 0x155f84u;
    WRITE8(ADD32(GPR_U32(ctx, 4), 2), (uint8_t)GPR_U32(ctx, 3));
    // 0x155f88: 0xa0820003  sb          $v0, 0x3($a0)
    ctx->pc = 0x155f88u;
    WRITE8(ADD32(GPR_U32(ctx, 4), 3), (uint8_t)GPR_U32(ctx, 2));
    // 0x155f8c: 0x80a80000  lb          $t0, 0x0($a1)
    ctx->pc = 0x155f8cu;
    SET_GPR_S32(ctx, 8, (int8_t)READ8(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x155f90: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x155f90u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x155f94: 0x80a70000  lb          $a3, 0x0($a1)
    ctx->pc = 0x155f94u;
    SET_GPR_S32(ctx, 7, (int8_t)READ8(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x155f98: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x155f98u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x155f9c: 0x80a30000  lb          $v1, 0x0($a1)
    ctx->pc = 0x155f9cu;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x155fa0: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x155fa0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x155fa4: 0x80a20000  lb          $v0, 0x0($a1)
    ctx->pc = 0x155fa4u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x155fa8: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x155fa8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x155fac: 0xa0880004  sb          $t0, 0x4($a0)
    ctx->pc = 0x155facu;
    WRITE8(ADD32(GPR_U32(ctx, 4), 4), (uint8_t)GPR_U32(ctx, 8));
    // 0x155fb0: 0xa0870005  sb          $a3, 0x5($a0)
    ctx->pc = 0x155fb0u;
    WRITE8(ADD32(GPR_U32(ctx, 4), 5), (uint8_t)GPR_U32(ctx, 7));
    // 0x155fb4: 0xa0830006  sb          $v1, 0x6($a0)
    ctx->pc = 0x155fb4u;
    WRITE8(ADD32(GPR_U32(ctx, 4), 6), (uint8_t)GPR_U32(ctx, 3));
    // 0x155fb8: 0xa0820007  sb          $v0, 0x7($a0)
    ctx->pc = 0x155fb8u;
    WRITE8(ADD32(GPR_U32(ctx, 4), 7), (uint8_t)GPR_U32(ctx, 2));
    // 0x155fbc: 0x80a80000  lb          $t0, 0x0($a1)
    ctx->pc = 0x155fbcu;
    SET_GPR_S32(ctx, 8, (int8_t)READ8(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x155fc0: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x155fc0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x155fc4: 0x80a70000  lb          $a3, 0x0($a1)
    ctx->pc = 0x155fc4u;
    SET_GPR_S32(ctx, 7, (int8_t)READ8(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x155fc8: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x155fc8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x155fcc: 0x80a30000  lb          $v1, 0x0($a1)
    ctx->pc = 0x155fccu;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x155fd0: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x155fd0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x155fd4: 0x80a20000  lb          $v0, 0x0($a1)
    ctx->pc = 0x155fd4u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x155fd8: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x155fd8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x155fdc: 0xa0880008  sb          $t0, 0x8($a0)
    ctx->pc = 0x155fdcu;
    WRITE8(ADD32(GPR_U32(ctx, 4), 8), (uint8_t)GPR_U32(ctx, 8));
    // 0x155fe0: 0xa0870009  sb          $a3, 0x9($a0)
    ctx->pc = 0x155fe0u;
    WRITE8(ADD32(GPR_U32(ctx, 4), 9), (uint8_t)GPR_U32(ctx, 7));
    // 0x155fe4: 0xa083000a  sb          $v1, 0xA($a0)
    ctx->pc = 0x155fe4u;
    WRITE8(ADD32(GPR_U32(ctx, 4), 10), (uint8_t)GPR_U32(ctx, 3));
    // 0x155fe8: 0xa082000b  sb          $v0, 0xB($a0)
    ctx->pc = 0x155fe8u;
    WRITE8(ADD32(GPR_U32(ctx, 4), 11), (uint8_t)GPR_U32(ctx, 2));
    // 0x155fec: 0x80a80000  lb          $t0, 0x0($a1)
    ctx->pc = 0x155fecu;
    SET_GPR_S32(ctx, 8, (int8_t)READ8(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x155ff0: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x155ff0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x155ff4: 0x80a70000  lb          $a3, 0x0($a1)
    ctx->pc = 0x155ff4u;
    SET_GPR_S32(ctx, 7, (int8_t)READ8(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x155ff8: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x155ff8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x155ffc: 0x80a30000  lb          $v1, 0x0($a1)
    ctx->pc = 0x155ffcu;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x156000: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x156000u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x156004: 0x80a20000  lb          $v0, 0x0($a1)
    ctx->pc = 0x156004u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x156008: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x156008u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x15600c: 0xa088000c  sb          $t0, 0xC($a0)
    ctx->pc = 0x15600cu;
    WRITE8(ADD32(GPR_U32(ctx, 4), 12), (uint8_t)GPR_U32(ctx, 8));
    // 0x156010: 0xa087000d  sb          $a3, 0xD($a0)
    ctx->pc = 0x156010u;
    WRITE8(ADD32(GPR_U32(ctx, 4), 13), (uint8_t)GPR_U32(ctx, 7));
    // 0x156014: 0xa083000e  sb          $v1, 0xE($a0)
    ctx->pc = 0x156014u;
    WRITE8(ADD32(GPR_U32(ctx, 4), 14), (uint8_t)GPR_U32(ctx, 3));
    // 0x156018: 0xa082000f  sb          $v0, 0xF($a0)
    ctx->pc = 0x156018u;
    WRITE8(ADD32(GPR_U32(ctx, 4), 15), (uint8_t)GPR_U32(ctx, 2));
    // 0x15601c: 0x24840010  addiu       $a0, $a0, 0x10
    ctx->pc = 0x15601cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 16));
    // 0x156020: 0x80a80000  lb          $t0, 0x0($a1)
    ctx->pc = 0x156020u;
    SET_GPR_S32(ctx, 8, (int8_t)READ8(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x156024: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x156024u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x156028: 0x80a70000  lb          $a3, 0x0($a1)
    ctx->pc = 0x156028u;
    SET_GPR_S32(ctx, 7, (int8_t)READ8(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x15602c: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x15602cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x156030: 0x80a30000  lb          $v1, 0x0($a1)
    ctx->pc = 0x156030u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x156034: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x156034u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x156038: 0x80a20000  lb          $v0, 0x0($a1)
    ctx->pc = 0x156038u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x15603c: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x15603cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x156040: 0xa0880000  sb          $t0, 0x0($a0)
    ctx->pc = 0x156040u;
    WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 8));
    // 0x156044: 0xa0870001  sb          $a3, 0x1($a0)
    ctx->pc = 0x156044u;
    WRITE8(ADD32(GPR_U32(ctx, 4), 1), (uint8_t)GPR_U32(ctx, 7));
    // 0x156048: 0xa0830002  sb          $v1, 0x2($a0)
    ctx->pc = 0x156048u;
    WRITE8(ADD32(GPR_U32(ctx, 4), 2), (uint8_t)GPR_U32(ctx, 3));
    // 0x15604c: 0xa0820003  sb          $v0, 0x3($a0)
    ctx->pc = 0x15604cu;
    WRITE8(ADD32(GPR_U32(ctx, 4), 3), (uint8_t)GPR_U32(ctx, 2));
    // 0x156050: 0x80a80000  lb          $t0, 0x0($a1)
    ctx->pc = 0x156050u;
    SET_GPR_S32(ctx, 8, (int8_t)READ8(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x156054: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x156054u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x156058: 0x80a70000  lb          $a3, 0x0($a1)
    ctx->pc = 0x156058u;
    SET_GPR_S32(ctx, 7, (int8_t)READ8(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x15605c: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x15605cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x156060: 0x80a30000  lb          $v1, 0x0($a1)
    ctx->pc = 0x156060u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x156064: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x156064u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x156068: 0x80a20000  lb          $v0, 0x0($a1)
    ctx->pc = 0x156068u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x15606c: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x15606cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x156070: 0xa0880004  sb          $t0, 0x4($a0)
    ctx->pc = 0x156070u;
    WRITE8(ADD32(GPR_U32(ctx, 4), 4), (uint8_t)GPR_U32(ctx, 8));
    // 0x156074: 0xa0870005  sb          $a3, 0x5($a0)
    ctx->pc = 0x156074u;
    WRITE8(ADD32(GPR_U32(ctx, 4), 5), (uint8_t)GPR_U32(ctx, 7));
    // 0x156078: 0xa0830006  sb          $v1, 0x6($a0)
    ctx->pc = 0x156078u;
    WRITE8(ADD32(GPR_U32(ctx, 4), 6), (uint8_t)GPR_U32(ctx, 3));
    // 0x15607c: 0xa0820007  sb          $v0, 0x7($a0)
    ctx->pc = 0x15607cu;
    WRITE8(ADD32(GPR_U32(ctx, 4), 7), (uint8_t)GPR_U32(ctx, 2));
    // 0x156080: 0x80a80000  lb          $t0, 0x0($a1)
    ctx->pc = 0x156080u;
    SET_GPR_S32(ctx, 8, (int8_t)READ8(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x156084: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x156084u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x156088: 0x80a70000  lb          $a3, 0x0($a1)
    ctx->pc = 0x156088u;
    SET_GPR_S32(ctx, 7, (int8_t)READ8(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x15608c: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x15608cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x156090: 0x80a30000  lb          $v1, 0x0($a1)
    ctx->pc = 0x156090u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x156094: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x156094u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x156098: 0x80a20000  lb          $v0, 0x0($a1)
    ctx->pc = 0x156098u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x15609c: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x15609cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x1560a0: 0xa0880008  sb          $t0, 0x8($a0)
    ctx->pc = 0x1560a0u;
    WRITE8(ADD32(GPR_U32(ctx, 4), 8), (uint8_t)GPR_U32(ctx, 8));
    // 0x1560a4: 0xa0870009  sb          $a3, 0x9($a0)
    ctx->pc = 0x1560a4u;
    WRITE8(ADD32(GPR_U32(ctx, 4), 9), (uint8_t)GPR_U32(ctx, 7));
    // 0x1560a8: 0xa083000a  sb          $v1, 0xA($a0)
    ctx->pc = 0x1560a8u;
    WRITE8(ADD32(GPR_U32(ctx, 4), 10), (uint8_t)GPR_U32(ctx, 3));
    // 0x1560ac: 0xa082000b  sb          $v0, 0xB($a0)
    ctx->pc = 0x1560acu;
    WRITE8(ADD32(GPR_U32(ctx, 4), 11), (uint8_t)GPR_U32(ctx, 2));
    // 0x1560b0: 0x80a80000  lb          $t0, 0x0($a1)
    ctx->pc = 0x1560b0u;
    SET_GPR_S32(ctx, 8, (int8_t)READ8(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x1560b4: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x1560b4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x1560b8: 0x80a70000  lb          $a3, 0x0($a1)
    ctx->pc = 0x1560b8u;
    SET_GPR_S32(ctx, 7, (int8_t)READ8(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x1560bc: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x1560bcu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x1560c0: 0x80a30000  lb          $v1, 0x0($a1)
    ctx->pc = 0x1560c0u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x1560c4: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x1560c4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x1560c8: 0x80a20000  lb          $v0, 0x0($a1)
    ctx->pc = 0x1560c8u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x1560cc: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x1560ccu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x1560d0: 0xa088000c  sb          $t0, 0xC($a0)
    ctx->pc = 0x1560d0u;
    WRITE8(ADD32(GPR_U32(ctx, 4), 12), (uint8_t)GPR_U32(ctx, 8));
    // 0x1560d4: 0xa087000d  sb          $a3, 0xD($a0)
    ctx->pc = 0x1560d4u;
    WRITE8(ADD32(GPR_U32(ctx, 4), 13), (uint8_t)GPR_U32(ctx, 7));
    // 0x1560d8: 0xa083000e  sb          $v1, 0xE($a0)
    ctx->pc = 0x1560d8u;
    WRITE8(ADD32(GPR_U32(ctx, 4), 14), (uint8_t)GPR_U32(ctx, 3));
    // 0x1560dc: 0xa082000f  sb          $v0, 0xF($a0)
    ctx->pc = 0x1560dcu;
    WRITE8(ADD32(GPR_U32(ctx, 4), 15), (uint8_t)GPR_U32(ctx, 2));
    // 0x1560e0: 0x14c0ff9d  bnez        $a2, . + 4 + (-0x63 << 2)
    ctx->pc = 0x1560E0u;
    {
        const bool branch_taken_0x1560e0 = (GPR_U64(ctx, 6) != GPR_U64(ctx, 0));
        ctx->pc = 0x1560E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1560E0u;
            // 0x1560e4: 0x24840010  addiu       $a0, $a0, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1560e0) {
            ctx->pc = 0x155F58u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_155f58;
        }
    }
    ctx->pc = 0x1560E8u;
label_1560e8:
    // 0x1560e8: 0x3e00008  jr          $ra
    ctx->pc = 0x1560E8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x155E60u: goto label_155e60;
            case 0x155E78u: goto label_155e78;
            case 0x155E90u: goto label_155e90;
            case 0x155EA8u: goto label_155ea8;
            case 0x155F30u: goto label_155f30;
            case 0x155F50u: goto label_155f50;
            case 0x155F58u: goto label_155f58;
            case 0x1560E8u: goto label_1560e8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1560F0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
