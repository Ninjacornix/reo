#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00150940
// Address: 0x150940 - 0x1509d0
void sub_00150940_0x150940(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00150940_0x150940");
#endif

    switch (ctx->pc) {
        case 0x15096cu: goto label_15096c;
        default: break;
    }

    ctx->pc = 0x150940u;

    // 0x150940: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x150940u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x150944: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x150944u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x150948: 0x24900128  addiu       $s0, $a0, 0x128
    ctx->pc = 0x150948u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 4), 296));
    // 0x15094c: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x15094cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x150950: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x150950u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x150954: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x150954u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x150958: 0xc0902d  daddu       $s2, $a2, $zero
    ctx->pc = 0x150958u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15095c: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x15095cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x150960: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x150960u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x150964: 0xc05578e  jal         func_155E38
    ctx->pc = 0x150964u;
    SET_GPR_U32(ctx, 31, 0x15096Cu);
    ctx->pc = 0x150968u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x150964u;
            // 0x150968: 0xe0982d  daddu       $s3, $a3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x155E38u;
    if (runtime->hasFunction(0x155E38u)) {
        auto targetFn = runtime->lookupFunction(0x155E38u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15096Cu; }
        if (ctx->pc != 0x15096Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00155E38_0x155e38(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15096Cu; }
        if (ctx->pc != 0x15096Cu) { return; }
    }
    ctx->pc = 0x15096Cu;
label_15096c:
    // 0x15096c: 0x3c05ff03  lui         $a1, 0xFF03
    ctx->pc = 0x15096cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65283 << 16));
    // 0x150970: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x150970u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x150974: 0x10400008  beqz        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x150974u;
    {
        const bool branch_taken_0x150974 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x150978u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x150974u;
            // 0x150978: 0x34a5020f  ori         $a1, $a1, 0x20F (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)527);
        ctx->in_delay_slot = false;
        if (branch_taken_0x150974) {
            ctx->pc = 0x150998u;
            goto label_150998;
        }
    }
    ctx->pc = 0x15097Cu;
    // 0x15097c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x15097cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x150980: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x150980u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x150984: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x150984u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x150988: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x150988u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x15098c: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x15098cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x150990: 0x805419c  j           func_150670
    ctx->pc = 0x150990u;
    ctx->pc = 0x150994u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x150990u;
            // 0x150994: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
    ctx->pc = 0x150670u;
    if (runtime->hasFunction(0x150670u)) {
        auto targetFn = runtime->lookupFunction(0x150670u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00150670_0x150670(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x150998u;
label_150998:
    // 0x150998: 0x8e0202fc  lw          $v0, 0x2FC($s0)
    ctx->pc = 0x150998u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 764)));
    // 0x15099c: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x15099cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1509a0: 0x212c0  sll         $v0, $v0, 11
    ctx->pc = 0x1509a0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 11));
    // 0x1509a4: 0xae220000  sw          $v0, 0x0($s1)
    ctx->pc = 0x1509a4u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 2));
    // 0x1509a8: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1509a8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1509ac: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1509acu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1509b0: 0x8e0300e4  lw          $v1, 0xE4($s0)
    ctx->pc = 0x1509b0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 228)));
    // 0x1509b4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1509b4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1509b8: 0xae430000  sw          $v1, 0x0($s2)
    ctx->pc = 0x1509b8u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 3));
    // 0x1509bc: 0xae620000  sw          $v0, 0x0($s3)
    ctx->pc = 0x1509bcu;
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 2));
    // 0x1509c0: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x1509c0u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1509c4: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x1509c4u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1509c8: 0x3e00008  jr          $ra
    ctx->pc = 0x1509C8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1509CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1509C8u;
            // 0x1509cc: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15096Cu: goto label_15096c;
            case 0x150998u: goto label_150998;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1509D0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
