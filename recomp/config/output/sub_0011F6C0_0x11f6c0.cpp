#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0011F6C0
// Address: 0x11f6c0 - 0x11f778
void sub_0011F6C0_0x11f6c0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0011F6C0_0x11f6c0");
#endif

    switch (ctx->pc) {
        case 0x11f734u: goto label_11f734;
        case 0x11f758u: goto label_11f758;
        default: break;
    }

    ctx->pc = 0x11f6c0u;

    // 0x11f6c0: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x11f6c0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x11f6c4: 0xffb30030  sd          $s3, 0x30($sp)
    ctx->pc = 0x11f6c4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 19));
    // 0x11f6c8: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x11f6c8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x11f6cc: 0xc0982d  daddu       $s3, $a2, $zero
    ctx->pc = 0x11f6ccu;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11f6d0: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x11f6d0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x11f6d4: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x11f6d4u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11f6d8: 0xffbf0040  sd          $ra, 0x40($sp)
    ctx->pc = 0x11f6d8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x11f6dc: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x11f6dcu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11f6e0: 0x6010008  bgez        $s0, . + 4 + (0x8 << 2)
    ctx->pc = 0x11F6E0u;
    {
        const bool branch_taken_0x11f6e0 = (GPR_S64(ctx, 16) >= 0);
        ctx->pc = 0x11F6E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11F6E0u;
            // 0x11f6e4: 0xffb10010  sd          $s1, 0x10($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11f6e0) {
            ctx->pc = 0x11F704u;
            goto label_11f704;
        }
    }
    ctx->pc = 0x11F6E8u;
    // 0x11f6e8: 0x3c027fff  lui         $v0, 0x7FFF
    ctx->pc = 0x11f6e8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32767 << 16));
    // 0x11f6ec: 0x3c030026  lui         $v1, 0x26
    ctx->pc = 0x11f6ecu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)38 << 16));
    // 0x11f6f0: 0x3442ffff  ori         $v0, $v0, 0xFFFF
    ctx->pc = 0x11f6f0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65535);
    // 0x11f6f4: 0x24711d08  addiu       $s1, $v1, 0x1D08
    ctx->pc = 0x11f6f4u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 3), 7432));
    // 0x11f6f8: 0x2028024  and         $s0, $s0, $v0
    ctx->pc = 0x11f6f8u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) & GPR_U64(ctx, 2));
    // 0x11f6fc: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x11F6FCu;
    {
        const bool branch_taken_0x11f6fc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11F700u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11F6FCu;
            // 0x11f700: 0x24020020  addiu       $v0, $zero, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11f6fc) {
            ctx->pc = 0x11F714u;
            goto label_11f714;
        }
    }
    ctx->pc = 0x11F704u;
label_11f704:
    // 0x11f704: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x11f704u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x11f708: 0x3c030021  lui         $v1, 0x21
    ctx->pc = 0x11f708u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)33 << 16));
    // 0x11f70c: 0x8c51b408  lw          $s1, -0x4BF8($v0)
    ctx->pc = 0x11f70cu;
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294947848)));
    // 0x11f710: 0x8c62b40c  lw          $v0, -0x4BF4($v1)
    ctx->pc = 0x11f710u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4294947852)));
label_11f714:
    // 0x11f714: 0x202102b  sltu        $v0, $s0, $v0
    ctx->pc = 0x11f714u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 16) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x11f718: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x11F718u;
    {
        const bool branch_taken_0x11f718 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x11f718) {
            ctx->pc = 0x11F72Cu;
            goto label_11f72c;
        }
    }
    ctx->pc = 0x11F720u;
    // 0x11f720: 0x3c028000  lui         $v0, 0x8000
    ctx->pc = 0x11f720u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32768 << 16));
    // 0x11f724: 0x1000000d  b           . + 4 + (0xD << 2)
    ctx->pc = 0x11F724u;
    {
        const bool branch_taken_0x11f724 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11F728u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11F724u;
            // 0x11f728: 0x34420069  ori         $v0, $v0, 0x69 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)105);
        ctx->in_delay_slot = false;
        if (branch_taken_0x11f724) {
            ctx->pc = 0x11F75Cu;
            goto label_11f75c;
        }
    }
    ctx->pc = 0x11F72Cu;
label_11f72c:
    // 0x11f72c: 0xc047598  jal         func_11D660
    ctx->pc = 0x11F72Cu;
    SET_GPR_U32(ctx, 31, 0x11F734u);
    ctx->pc = 0x11D660u;
    if (runtime->hasFunction(0x11D660u)) {
        auto targetFn = runtime->lookupFunction(0x11D660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11F734u; }
        if (ctx->pc != 0x11F734u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D660_0x11d660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11F734u; }
        if (ctx->pc != 0x11F734u) { return; }
    }
    ctx->pc = 0x11F734u;
label_11f734:
    // 0x11f734: 0x101900  sll         $v1, $s0, 4
    ctx->pc = 0x11f734u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 16), 4));
    // 0x11f738: 0x711821  addu        $v1, $v1, $s1
    ctx->pc = 0x11f738u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 17)));
    // 0x11f73c: 0xac720000  sw          $s2, 0x0($v1)
    ctx->pc = 0x11f73cu;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 18));
    // 0x11f740: 0xac730004  sw          $s3, 0x4($v1)
    ctx->pc = 0x11f740u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 4), GPR_U32(ctx, 19));
    // 0x11f744: 0x380202d  daddu       $a0, $gp, $zero
    ctx->pc = 0x11f744u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 28) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11f748: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x11F748u;
    {
        const bool branch_taken_0x11f748 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x11F74Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11F748u;
            // 0x11f74c: 0xac640008  sw          $a0, 0x8($v1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 3), 8), GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11f748) {
            ctx->pc = 0x11F758u;
            goto label_11f758;
        }
    }
    ctx->pc = 0x11F750u;
    // 0x11f750: 0xc0475ae  jal         func_11D6B8
    ctx->pc = 0x11F750u;
    SET_GPR_U32(ctx, 31, 0x11F758u);
    ctx->pc = 0x11D6B8u;
    if (runtime->hasFunction(0x11D6B8u)) {
        auto targetFn = runtime->lookupFunction(0x11D6B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11F758u; }
        if (ctx->pc != 0x11F758u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D6B8_0x11d6b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11F758u; }
        if (ctx->pc != 0x11F758u) { return; }
    }
    ctx->pc = 0x11F758u;
label_11f758:
    // 0x11f758: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x11f758u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_11f75c:
    // 0x11f75c: 0xdfbf0040  ld          $ra, 0x40($sp)
    ctx->pc = 0x11f75cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x11f760: 0xdfb30030  ld          $s3, 0x30($sp)
    ctx->pc = 0x11f760u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x11f764: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x11f764u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x11f768: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x11f768u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x11f76c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x11f76cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x11f770: 0x3e00008  jr          $ra
    ctx->pc = 0x11F770u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11F774u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11F770u;
            // 0x11f774: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11F704u: goto label_11f704;
            case 0x11F714u: goto label_11f714;
            case 0x11F72Cu: goto label_11f72c;
            case 0x11F734u: goto label_11f734;
            case 0x11F758u: goto label_11f758;
            case 0x11F75Cu: goto label_11f75c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11F778u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
