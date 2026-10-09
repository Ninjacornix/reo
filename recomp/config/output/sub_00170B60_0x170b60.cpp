#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00170B60
// Address: 0x170b60 - 0x170ca0
void sub_00170B60_0x170b60(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00170B60_0x170b60");
#endif

    switch (ctx->pc) {
        case 0x170ba8u: goto label_170ba8;
        case 0x170be8u: goto label_170be8;
        case 0x170c10u: goto label_170c10;
        case 0x170c44u: goto label_170c44;
        case 0x170c80u: goto label_170c80;
        default: break;
    }

    ctx->pc = 0x170b60u;

    // 0x170b60: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x170b60u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x170b64: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x170b64u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x170b68: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x170b68u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x170b6c: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x170b6cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x170b70: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x170b70u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x170b74: 0x902d  daddu       $s2, $zero, $zero
    ctx->pc = 0x170b74u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x170b78: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x170b78u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x170b7c: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x170b7cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x170b80: 0xae220044  sw          $v0, 0x44($s1)
    ctx->pc = 0x170b80u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 68), GPR_U32(ctx, 2));
    // 0x170b84: 0x8e230054  lw          $v1, 0x54($s1)
    ctx->pc = 0x170b84u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 84)));
    // 0x170b88: 0xae20000c  sw          $zero, 0xC($s1)
    ctx->pc = 0x170b88u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 12), GPR_U32(ctx, 0));
    // 0x170b8c: 0xae200010  sw          $zero, 0x10($s1)
    ctx->pc = 0x170b8cu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 16), GPR_U32(ctx, 0));
    // 0x170b90: 0xae200014  sw          $zero, 0x14($s1)
    ctx->pc = 0x170b90u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 20), GPR_U32(ctx, 0));
    // 0x170b94: 0xae200058  sw          $zero, 0x58($s1)
    ctx->pc = 0x170b94u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 88), GPR_U32(ctx, 0));
    // 0x170b98: 0x1860000c  blez        $v1, . + 4 + (0xC << 2)
    ctx->pc = 0x170B98u;
    {
        const bool branch_taken_0x170b98 = (GPR_S64(ctx, 3) <= 0);
        ctx->pc = 0x170B9Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x170B98u;
            // 0x170b9c: 0xae20005c  sw          $zero, 0x5C($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 92), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x170b98) {
            ctx->pc = 0x170BCCu;
            goto label_170bcc;
        }
    }
    ctx->pc = 0x170BA0u;
    // 0x170ba0: 0x8e230050  lw          $v1, 0x50($s1)
    ctx->pc = 0x170ba0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 80)));
    // 0x170ba4: 0x2404ffff  addiu       $a0, $zero, -0x1
    ctx->pc = 0x170ba4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
label_170ba8:
    // 0x170ba8: 0xac600010  sw          $zero, 0x10($v1)
    ctx->pc = 0x170ba8u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 16), GPR_U32(ctx, 0));
    // 0x170bac: 0x26520001  addiu       $s2, $s2, 0x1
    ctx->pc = 0x170bacu;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 1));
    // 0x170bb0: 0xac600014  sw          $zero, 0x14($v1)
    ctx->pc = 0x170bb0u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 20), GPR_U32(ctx, 0));
    // 0x170bb4: 0xfc640000  sd          $a0, 0x0($v1)
    ctx->pc = 0x170bb4u;
    WRITE64(ADD32(GPR_U32(ctx, 3), 0), GPR_U64(ctx, 4));
    // 0x170bb8: 0x8e220054  lw          $v0, 0x54($s1)
    ctx->pc = 0x170bb8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 84)));
    // 0x170bbc: 0xfc640008  sd          $a0, 0x8($v1)
    ctx->pc = 0x170bbcu;
    WRITE64(ADD32(GPR_U32(ctx, 3), 8), GPR_U64(ctx, 4));
    // 0x170bc0: 0x242102a  slt         $v0, $s2, $v0
    ctx->pc = 0x170bc0u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 18) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x170bc4: 0x1440fff8  bnez        $v0, . + 4 + (-0x8 << 2)
    ctx->pc = 0x170BC4u;
    {
        const bool branch_taken_0x170bc4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x170BC8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x170BC4u;
            // 0x170bc8: 0x24630018  addiu       $v1, $v1, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 24));
        ctx->in_delay_slot = false;
        if (branch_taken_0x170bc4) {
            ctx->pc = 0x170BA8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_170ba8;
        }
    }
    ctx->pc = 0x170BCCu;
label_170bcc:
    // 0x170bcc: 0x8e220008  lw          $v0, 0x8($s1)
    ctx->pc = 0x170bccu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 8)));
    // 0x170bd0: 0x18400013  blez        $v0, . + 4 + (0x13 << 2)
    ctx->pc = 0x170BD0u;
    {
        const bool branch_taken_0x170bd0 = (GPR_S64(ctx, 2) <= 0);
        ctx->pc = 0x170BD4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x170BD0u;
            // 0x170bd4: 0x902d  daddu       $s2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x170bd0) {
            ctx->pc = 0x170C20u;
            goto label_170c20;
        }
    }
    ctx->pc = 0x170BD8u;
    // 0x170bd8: 0x3c100fff  lui         $s0, 0xFFF
    ctx->pc = 0x170bd8u;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)4095 << 16));
    // 0x170bdc: 0x3610ffff  ori         $s0, $s0, 0xFFFF
    ctx->pc = 0x170bdcu;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | (uint64_t)(uint16_t)65535);
    // 0x170be0: 0x8e220000  lw          $v0, 0x0($s1)
    ctx->pc = 0x170be0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x170be4: 0x0  nop
    ctx->pc = 0x170be4u;
    // NOP
label_170be8:
    // 0x170be8: 0x122ac0  sll         $a1, $s2, 11
    ctx->pc = 0x170be8u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 18), 11));
    // 0x170bec: 0x8e230004  lw          $v1, 0x4($s1)
    ctx->pc = 0x170becu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x170bf0: 0x122100  sll         $a0, $s2, 4
    ctx->pc = 0x170bf0u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 18), 4));
    // 0x170bf4: 0xa22821  addu        $a1, $a1, $v0
    ctx->pc = 0x170bf4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
    // 0x170bf8: 0x24060003  addiu       $a2, $zero, 0x3
    ctx->pc = 0x170bf8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x170bfc: 0x642021  addu        $a0, $v1, $a0
    ctx->pc = 0x170bfcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x170c00: 0xb02824  and         $a1, $a1, $s0
    ctx->pc = 0x170c00u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) & GPR_U64(ctx, 16));
    // 0x170c04: 0x24070080  addiu       $a3, $zero, 0x80
    ctx->pc = 0x170c04u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 128));
    // 0x170c08: 0xc05c2b0  jal         func_170AC0
    ctx->pc = 0x170C08u;
    SET_GPR_U32(ctx, 31, 0x170C10u);
    ctx->pc = 0x170C0Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x170C08u;
            // 0x170c0c: 0x26520001  addiu       $s2, $s2, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x170AC0u;
    if (runtime->hasFunction(0x170AC0u)) {
        auto targetFn = runtime->lookupFunction(0x170AC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x170C10u; }
        if (ctx->pc != 0x170C10u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00170AC0_0x170ac0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x170C10u; }
        if (ctx->pc != 0x170C10u) { return; }
    }
    ctx->pc = 0x170C10u;
label_170c10:
    // 0x170c10: 0x8e220008  lw          $v0, 0x8($s1)
    ctx->pc = 0x170c10u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 8)));
    // 0x170c14: 0x242102a  slt         $v0, $s2, $v0
    ctx->pc = 0x170c14u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 18) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x170c18: 0x5440fff3  bnel        $v0, $zero, . + 4 + (-0xD << 2)
    ctx->pc = 0x170C18u;
    {
        const bool branch_taken_0x170c18 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x170c18) {
            ctx->pc = 0x170C1Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x170C18u;
            // 0x170c1c: 0x8e220000  lw          $v0, 0x0($s1) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x170BE8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_170be8;
        }
    }
    ctx->pc = 0x170C20u;
label_170c20:
    // 0x170c20: 0x8e250004  lw          $a1, 0x4($s1)
    ctx->pc = 0x170c20u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x170c24: 0x3c100fff  lui         $s0, 0xFFF
    ctx->pc = 0x170c24u;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)4095 << 16));
    // 0x170c28: 0x3610ffff  ori         $s0, $s0, 0xFFFF
    ctx->pc = 0x170c28u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | (uint64_t)(uint16_t)65535);
    // 0x170c2c: 0x122100  sll         $a0, $s2, 4
    ctx->pc = 0x170c2cu;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 18), 4));
    // 0x170c30: 0xa42021  addu        $a0, $a1, $a0
    ctx->pc = 0x170c30u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 4)));
    // 0x170c34: 0xb02824  and         $a1, $a1, $s0
    ctx->pc = 0x170c34u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) & GPR_U64(ctx, 16));
    // 0x170c38: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x170c38u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x170c3c: 0xc05c2b0  jal         func_170AC0
    ctx->pc = 0x170C3Cu;
    SET_GPR_U32(ctx, 31, 0x170C44u);
    ctx->pc = 0x170C40u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x170C3Cu;
            // 0x170c40: 0x24060002  addiu       $a2, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x170AC0u;
    if (runtime->hasFunction(0x170AC0u)) {
        auto targetFn = runtime->lookupFunction(0x170AC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x170C44u; }
        if (ctx->pc != 0x170C44u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00170AC0_0x170ac0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x170C44u; }
        if (ctx->pc != 0x170C44u) { return; }
    }
    ctx->pc = 0x170C44u;
label_170c44:
    // 0x170c44: 0x3c041000  lui         $a0, 0x1000
    ctx->pc = 0x170c44u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)4096 << 16));
    // 0x170c48: 0x8e260004  lw          $a2, 0x4($s1)
    ctx->pc = 0x170c48u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x170c4c: 0x3c031000  lui         $v1, 0x1000
    ctx->pc = 0x170c4cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)4096 << 16));
    // 0x170c50: 0x8e220000  lw          $v0, 0x0($s1)
    ctx->pc = 0x170c50u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x170c54: 0x3c051000  lui         $a1, 0x1000
    ctx->pc = 0x170c54u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)4096 << 16));
    // 0x170c58: 0xd03024  and         $a2, $a2, $s0
    ctx->pc = 0x170c58u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) & GPR_U64(ctx, 16));
    // 0x170c5c: 0x3463b410  ori         $v1, $v1, 0xB410
    ctx->pc = 0x170c5cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)46096);
    // 0x170c60: 0x501024  and         $v0, $v0, $s0
    ctx->pc = 0x170c60u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 16));
    // 0x170c64: 0x34a5b430  ori         $a1, $a1, 0xB430
    ctx->pc = 0x170c64u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)46128);
    // 0x170c68: 0x3484b420  ori         $a0, $a0, 0xB420
    ctx->pc = 0x170c68u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)46112);
    // 0x170c6c: 0xac800000  sw          $zero, 0x0($a0)
    ctx->pc = 0x170c6cu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 0));
    // 0x170c70: 0x24040005  addiu       $a0, $zero, 0x5
    ctx->pc = 0x170c70u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0x170c74: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x170c74u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x170c78: 0xc05c296  jal         func_170A58
    ctx->pc = 0x170C78u;
    SET_GPR_U32(ctx, 31, 0x170C80u);
    ctx->pc = 0x170C7Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x170C78u;
            // 0x170c7c: 0xaca60000  sw          $a2, 0x0($a1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 6));
        ctx->in_delay_slot = false;
    ctx->pc = 0x170A58u;
    if (runtime->hasFunction(0x170A58u)) {
        auto targetFn = runtime->lookupFunction(0x170A58u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x170C80u; }
        if (ctx->pc != 0x170C80u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00170A58_0x170a58(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x170C80u; }
        if (ctx->pc != 0x170C80u) { return; }
    }
    ctx->pc = 0x170C80u;
label_170c80:
    // 0x170c80: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x170c80u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x170c84: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x170c84u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x170c88: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x170c88u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x170c8c: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x170c8cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x170c90: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x170c90u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x170c94: 0x3e00008  jr          $ra
    ctx->pc = 0x170C94u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x170C98u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x170C94u;
            // 0x170c98: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x170BA8u: goto label_170ba8;
            case 0x170BCCu: goto label_170bcc;
            case 0x170BE8u: goto label_170be8;
            case 0x170C10u: goto label_170c10;
            case 0x170C20u: goto label_170c20;
            case 0x170C44u: goto label_170c44;
            case 0x170C80u: goto label_170c80;
            default: break;
        }
        return;
    }
    ctx->pc = 0x170C9Cu;
    // 0x170c9c: 0x0  nop
    ctx->pc = 0x170c9cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
