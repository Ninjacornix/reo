#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00137E90
// Address: 0x137e90 - 0x137fe8
void sub_00137E90_0x137e90(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00137E90_0x137e90");
#endif

    switch (ctx->pc) {
        case 0x137ec0u: goto label_137ec0;
        case 0x137eecu: goto label_137eec;
        case 0x137f0cu: goto label_137f0c;
        case 0x137f44u: goto label_137f44;
        case 0x137f7cu: goto label_137f7c;
        case 0x137fb4u: goto label_137fb4;
        default: break;
    }

    ctx->pc = 0x137e90u;

label_137e90:
    // 0x137e90: 0x3c020022  lui         $v0, 0x22
    ctx->pc = 0x137e90u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)34 << 16));
    // 0x137e94: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x137e94u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x137e98: 0x2442bbd8  addiu       $v0, $v0, -0x4428
    ctx->pc = 0x137e98u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294949848));
    // 0x137e9c: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x137e9cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x137ea0: 0xac400000  sw          $zero, 0x0($v0)
    ctx->pc = 0x137ea0u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 0));
    // 0x137ea4: 0x3c080022  lui         $t0, 0x22
    ctx->pc = 0x137ea4u;
    SET_GPR_S32(ctx, 8, (int32_t)((uint32_t)34 << 16));
    // 0x137ea8: 0x24070001  addiu       $a3, $zero, 0x1
    ctx->pc = 0x137ea8u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x137eac: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x137eacu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x137eb0: 0x3c061964  lui         $a2, 0x1964
    ctx->pc = 0x137eb0u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)6500 << 16));
    // 0x137eb4: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x137eb4u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x137eb8: 0x8d02bbc4  lw          $v0, -0x443C($t0)
    ctx->pc = 0x137eb8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 8), 4294949828)));
    // 0x137ebc: 0x0  nop
    ctx->pc = 0x137ebcu;
    // NOP
label_137ec0:
    // 0x137ec0: 0x1447000b  bne         $v0, $a3, . + 4 + (0xB << 2)
    ctx->pc = 0x137EC0u;
    {
        const bool branch_taken_0x137ec0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 7));
        ctx->pc = 0x137EC4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x137EC0u;
            // 0x137ec4: 0xdfbf0000  ld          $ra, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x137ec0) {
            ctx->pc = 0x137EF0u;
            goto label_137ef0;
        }
    }
    ctx->pc = 0x137EC8u;
    // 0x137ec8: 0x8ca20000  lw          $v0, 0x0($a1)
    ctx->pc = 0x137ec8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x137ecc: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x137eccu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x137ed0: 0xaca20000  sw          $v0, 0x0($a1)
    ctx->pc = 0x137ed0u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 2));
    // 0x137ed4: 0x8ca30000  lw          $v1, 0x0($a1)
    ctx->pc = 0x137ed4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x137ed8: 0xc3182b  sltu        $v1, $a2, $v1
    ctx->pc = 0x137ed8u;
    SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 6) < (uint64_t)GPR_U64(ctx, 3)) ? 1 : 0);
    // 0x137edc: 0x5060fff8  beql        $v1, $zero, . + 4 + (-0x8 << 2)
    ctx->pc = 0x137EDCu;
    {
        const bool branch_taken_0x137edc = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x137edc) {
            ctx->pc = 0x137EE0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x137EDCu;
            // 0x137ee0: 0x8d02bbc4  lw          $v0, -0x443C($t0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 8), 4294949828)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x137EC0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_137ec0;
        }
    }
    ctx->pc = 0x137EE4u;
    // 0x137ee4: 0xc045a12  jal         func_116848
    ctx->pc = 0x137EE4u;
    SET_GPR_U32(ctx, 31, 0x137EECu);
    ctx->pc = 0x137EE8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x137EE4u;
            // 0x137ee8: 0x2484c5c8  addiu       $a0, $a0, -0x3A38 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294952392));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x137EECu; }
        if (ctx->pc != 0x137EECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x137EECu; }
        if (ctx->pc != 0x137EECu) { return; }
    }
    ctx->pc = 0x137EECu;
label_137eec:
    // 0x137eec: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x137eecu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_137ef0:
    // 0x137ef0: 0x3e00008  jr          $ra
    ctx->pc = 0x137EF0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x137EF4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x137EF0u;
            // 0x137ef4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x137E90u: goto label_137e90;
            case 0x137EC0u: goto label_137ec0;
            case 0x137EECu: goto label_137eec;
            case 0x137EF0u: goto label_137ef0;
            case 0x137F0Cu: goto label_137f0c;
            case 0x137F44u: goto label_137f44;
            case 0x137F7Cu: goto label_137f7c;
            case 0x137FB4u: goto label_137fb4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x137EF8u;
    // 0x137ef8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x137ef8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x137efc: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x137efcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x137f00: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x137f00u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x137f04: 0xc04dfa4  jal         func_137E90
    ctx->pc = 0x137F04u;
    SET_GPR_U32(ctx, 31, 0x137F0Cu);
    ctx->pc = 0x137F08u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x137F04u;
            // 0x137f08: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x137E90u;
    goto label_137e90;
    ctx->pc = 0x137F0Cu;
label_137f0c:
    // 0x137f0c: 0x108600  sll         $s0, $s0, 24
    ctx->pc = 0x137f0cu;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 24));
    // 0x137f10: 0x3c020022  lui         $v0, 0x22
    ctx->pc = 0x137f10u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)34 << 16));
    // 0x137f14: 0x2442bbc8  addiu       $v0, $v0, -0x4438
    ctx->pc = 0x137f14u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294949832));
    // 0x137f18: 0x108603  sra         $s0, $s0, 24
    ctx->pc = 0x137f18u;
    SET_GPR_S32(ctx, 16, SRA32(GPR_S32(ctx, 16), 24));
    // 0x137f1c: 0xac500000  sw          $s0, 0x0($v0)
    ctx->pc = 0x137f1cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 16));
    // 0x137f20: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x137f20u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x137f24: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x137f24u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x137f28: 0x3e00008  jr          $ra
    ctx->pc = 0x137F28u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x137F2Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x137F28u;
            // 0x137f2c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x137E90u: goto label_137e90;
            case 0x137EC0u: goto label_137ec0;
            case 0x137EECu: goto label_137eec;
            case 0x137EF0u: goto label_137ef0;
            case 0x137F0Cu: goto label_137f0c;
            case 0x137F44u: goto label_137f44;
            case 0x137F7Cu: goto label_137f7c;
            case 0x137FB4u: goto label_137fb4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x137F30u;
    // 0x137f30: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x137f30u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x137f34: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x137f34u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x137f38: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x137f38u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x137f3c: 0xc04dfa4  jal         func_137E90
    ctx->pc = 0x137F3Cu;
    SET_GPR_U32(ctx, 31, 0x137F44u);
    ctx->pc = 0x137F40u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x137F3Cu;
            // 0x137f40: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x137E90u;
    goto label_137e90;
    ctx->pc = 0x137F44u;
label_137f44:
    // 0x137f44: 0x108600  sll         $s0, $s0, 24
    ctx->pc = 0x137f44u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 24));
    // 0x137f48: 0x3c020022  lui         $v0, 0x22
    ctx->pc = 0x137f48u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)34 << 16));
    // 0x137f4c: 0x2442bbcc  addiu       $v0, $v0, -0x4434
    ctx->pc = 0x137f4cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294949836));
    // 0x137f50: 0x108603  sra         $s0, $s0, 24
    ctx->pc = 0x137f50u;
    SET_GPR_S32(ctx, 16, SRA32(GPR_S32(ctx, 16), 24));
    // 0x137f54: 0xac500000  sw          $s0, 0x0($v0)
    ctx->pc = 0x137f54u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 16));
    // 0x137f58: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x137f58u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x137f5c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x137f5cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x137f60: 0x3e00008  jr          $ra
    ctx->pc = 0x137F60u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x137F64u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x137F60u;
            // 0x137f64: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x137E90u: goto label_137e90;
            case 0x137EC0u: goto label_137ec0;
            case 0x137EECu: goto label_137eec;
            case 0x137EF0u: goto label_137ef0;
            case 0x137F0Cu: goto label_137f0c;
            case 0x137F44u: goto label_137f44;
            case 0x137F7Cu: goto label_137f7c;
            case 0x137FB4u: goto label_137fb4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x137F68u;
    // 0x137f68: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x137f68u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x137f6c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x137f6cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x137f70: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x137f70u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x137f74: 0xc04dfa4  jal         func_137E90
    ctx->pc = 0x137F74u;
    SET_GPR_U32(ctx, 31, 0x137F7Cu);
    ctx->pc = 0x137F78u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x137F74u;
            // 0x137f78: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x137E90u;
    goto label_137e90;
    ctx->pc = 0x137F7Cu;
label_137f7c:
    // 0x137f7c: 0x108600  sll         $s0, $s0, 24
    ctx->pc = 0x137f7cu;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 24));
    // 0x137f80: 0x3c020022  lui         $v0, 0x22
    ctx->pc = 0x137f80u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)34 << 16));
    // 0x137f84: 0x2442bbd0  addiu       $v0, $v0, -0x4430
    ctx->pc = 0x137f84u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294949840));
    // 0x137f88: 0x108603  sra         $s0, $s0, 24
    ctx->pc = 0x137f88u;
    SET_GPR_S32(ctx, 16, SRA32(GPR_S32(ctx, 16), 24));
    // 0x137f8c: 0xac500000  sw          $s0, 0x0($v0)
    ctx->pc = 0x137f8cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 16));
    // 0x137f90: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x137f90u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x137f94: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x137f94u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x137f98: 0x3e00008  jr          $ra
    ctx->pc = 0x137F98u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x137F9Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x137F98u;
            // 0x137f9c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x137E90u: goto label_137e90;
            case 0x137EC0u: goto label_137ec0;
            case 0x137EECu: goto label_137eec;
            case 0x137EF0u: goto label_137ef0;
            case 0x137F0Cu: goto label_137f0c;
            case 0x137F44u: goto label_137f44;
            case 0x137F7Cu: goto label_137f7c;
            case 0x137FB4u: goto label_137fb4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x137FA0u;
    // 0x137fa0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x137fa0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x137fa4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x137fa4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x137fa8: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x137fa8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x137fac: 0xc04dfa4  jal         func_137E90
    ctx->pc = 0x137FACu;
    SET_GPR_U32(ctx, 31, 0x137FB4u);
    ctx->pc = 0x137FB0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x137FACu;
            // 0x137fb0: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x137E90u;
    goto label_137e90;
    ctx->pc = 0x137FB4u;
label_137fb4:
    // 0x137fb4: 0x108600  sll         $s0, $s0, 24
    ctx->pc = 0x137fb4u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 24));
    // 0x137fb8: 0x3c020022  lui         $v0, 0x22
    ctx->pc = 0x137fb8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)34 << 16));
    // 0x137fbc: 0x2442bbd4  addiu       $v0, $v0, -0x442C
    ctx->pc = 0x137fbcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294949844));
    // 0x137fc0: 0x108603  sra         $s0, $s0, 24
    ctx->pc = 0x137fc0u;
    SET_GPR_S32(ctx, 16, SRA32(GPR_S32(ctx, 16), 24));
    // 0x137fc4: 0xac500000  sw          $s0, 0x0($v0)
    ctx->pc = 0x137fc4u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 16));
    // 0x137fc8: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x137fc8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x137fcc: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x137fccu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x137fd0: 0x3e00008  jr          $ra
    ctx->pc = 0x137FD0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x137FD4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x137FD0u;
            // 0x137fd4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x137E90u: goto label_137e90;
            case 0x137EC0u: goto label_137ec0;
            case 0x137EECu: goto label_137eec;
            case 0x137EF0u: goto label_137ef0;
            case 0x137F0Cu: goto label_137f0c;
            case 0x137F44u: goto label_137f44;
            case 0x137F7Cu: goto label_137f7c;
            case 0x137FB4u: goto label_137fb4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x137FD8u;
    // 0x137fd8: 0x3c030022  lui         $v1, 0x22
    ctx->pc = 0x137fd8u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)34 << 16));
    // 0x137fdc: 0x24020009  addiu       $v0, $zero, 0x9
    ctx->pc = 0x137fdcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 9));
    // 0x137fe0: 0x3e00008  jr          $ra
    ctx->pc = 0x137FE0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x137FE4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x137FE0u;
            // 0x137fe4: 0xa062bb8a  sb          $v0, -0x4476($v1) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 3), 4294949770), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x137E90u: goto label_137e90;
            case 0x137EC0u: goto label_137ec0;
            case 0x137EECu: goto label_137eec;
            case 0x137EF0u: goto label_137ef0;
            case 0x137F0Cu: goto label_137f0c;
            case 0x137F44u: goto label_137f44;
            case 0x137F7Cu: goto label_137f7c;
            case 0x137FB4u: goto label_137fb4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x137FE8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
