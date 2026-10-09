#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00100590
// Address: 0x100590 - 0x100648
void sub_00100590_0x100590(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00100590_0x100590");
#endif

    switch (ctx->pc) {
        case 0x1005f8u: goto label_1005f8;
        case 0x100604u: goto label_100604;
        case 0x100610u: goto label_100610;
        case 0x100620u: goto label_100620;
        default: break;
    }

    ctx->pc = 0x100590u;

    // 0x100590: 0x27bdffa0  addiu       $sp, $sp, -0x60
    ctx->pc = 0x100590u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967200));
    // 0x100594: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x100594u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x100598: 0xffb10030  sd          $s1, 0x30($sp)
    ctx->pc = 0x100598u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 17));
    // 0x10059c: 0x3c110020  lui         $s1, 0x20
    ctx->pc = 0x10059cu;
    SET_GPR_S32(ctx, 17, (int32_t)((uint32_t)32 << 16));
    // 0x1005a0: 0xffbf0050  sd          $ra, 0x50($sp)
    ctx->pc = 0x1005a0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 31));
    // 0x1005a4: 0x8e227928  lw          $v0, 0x7928($s1)
    ctx->pc = 0x1005a4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 31016)));
    // 0x1005a8: 0xffb20040  sd          $s2, 0x40($sp)
    ctx->pc = 0x1005a8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 18));
    // 0x1005ac: 0x1043000a  beq         $v0, $v1, . + 4 + (0xA << 2)
    ctx->pc = 0x1005ACu;
    {
        const bool branch_taken_0x1005ac = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        ctx->pc = 0x1005B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1005ACu;
            // 0x1005b0: 0xffb00020  sd          $s0, 0x20($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1005ac) {
            ctx->pc = 0x1005D8u;
            goto label_1005d8;
        }
    }
    ctx->pc = 0x1005B4u;
    // 0x1005b4: 0x3c100020  lui         $s0, 0x20
    ctx->pc = 0x1005b4u;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)32 << 16));
    // 0x1005b8: 0x8e02792c  lw          $v0, 0x792C($s0)
    ctx->pc = 0x1005b8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 31020)));
    // 0x1005bc: 0x10430007  beq         $v0, $v1, . + 4 + (0x7 << 2)
    ctx->pc = 0x1005BCu;
    {
        const bool branch_taken_0x1005bc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        ctx->pc = 0x1005C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1005BCu;
            // 0x1005c0: 0x3c120020  lui         $s2, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)((uint32_t)32 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1005bc) {
            ctx->pc = 0x1005DCu;
            goto label_1005dc;
        }
    }
    ctx->pc = 0x1005C4u;
    // 0x1005c4: 0x8e427930  lw          $v0, 0x7930($s2)
    ctx->pc = 0x1005c4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 31024)));
    // 0x1005c8: 0x1443001a  bne         $v0, $v1, . + 4 + (0x1A << 2)
    ctx->pc = 0x1005C8u;
    {
        const bool branch_taken_0x1005c8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        ctx->pc = 0x1005CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1005C8u;
            // 0x1005cc: 0xdfbf0050  ld          $ra, 0x50($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 80)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1005c8) {
            ctx->pc = 0x100634u;
            goto label_100634;
        }
    }
    ctx->pc = 0x1005D0u;
    // 0x1005d0: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1005D0u;
    {
        const bool branch_taken_0x1005d0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1005D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1005D0u;
            // 0x1005d4: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1005d0) {
            ctx->pc = 0x1005E4u;
            goto label_1005e4;
        }
    }
    ctx->pc = 0x1005D8u;
label_1005d8:
    // 0x1005d8: 0x3c100020  lui         $s0, 0x20
    ctx->pc = 0x1005d8u;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)32 << 16));
label_1005dc:
    // 0x1005dc: 0x3c120020  lui         $s2, 0x20
    ctx->pc = 0x1005dcu;
    SET_GPR_S32(ctx, 18, (int32_t)((uint32_t)32 << 16));
    // 0x1005e0: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1005e0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_1005e4:
    // 0x1005e4: 0xafa00014  sw          $zero, 0x14($sp)
    ctx->pc = 0x1005e4u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 0));
    // 0x1005e8: 0xafa20004  sw          $v0, 0x4($sp)
    ctx->pc = 0x1005e8u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 4), GPR_U32(ctx, 2));
    // 0x1005ec: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x1005ecu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1005f0: 0xc045188  jal         func_114620
    ctx->pc = 0x1005F0u;
    SET_GPR_U32(ctx, 31, 0x1005F8u);
    ctx->pc = 0x1005F4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1005F0u;
            // 0x1005f4: 0xafa20008  sw          $v0, 0x8($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114620u;
    if (runtime->hasFunction(0x114620u)) {
        auto targetFn = runtime->lookupFunction(0x114620u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1005F8u; }
        if (ctx->pc != 0x1005F8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114620_0x114620(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1005F8u; }
        if (ctx->pc != 0x1005F8u) { return; }
    }
    ctx->pc = 0x1005F8u;
label_1005f8:
    // 0x1005f8: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x1005f8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1005fc: 0xc045188  jal         func_114620
    ctx->pc = 0x1005FCu;
    SET_GPR_U32(ctx, 31, 0x100604u);
    ctx->pc = 0x100600u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1005FCu;
            // 0x100600: 0xae227928  sw          $v0, 0x7928($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 31016), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114620u;
    if (runtime->hasFunction(0x114620u)) {
        auto targetFn = runtime->lookupFunction(0x114620u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100604u; }
        if (ctx->pc != 0x100604u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114620_0x114620(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100604u; }
        if (ctx->pc != 0x100604u) { return; }
    }
    ctx->pc = 0x100604u;
label_100604:
    // 0x100604: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x100604u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x100608: 0xc045188  jal         func_114620
    ctx->pc = 0x100608u;
    SET_GPR_U32(ctx, 31, 0x100610u);
    ctx->pc = 0x10060Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x100608u;
            // 0x10060c: 0xae02792c  sw          $v0, 0x792C($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 31020), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114620u;
    if (runtime->hasFunction(0x114620u)) {
        auto targetFn = runtime->lookupFunction(0x114620u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100610u; }
        if (ctx->pc != 0x100610u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114620_0x114620(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100610u; }
        if (ctx->pc != 0x100610u) { return; }
    }
    ctx->pc = 0x100610u;
label_100610:
    // 0x100610: 0xae427930  sw          $v0, 0x7930($s2)
    ctx->pc = 0x100610u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 31024), GPR_U32(ctx, 2));
    // 0x100614: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x100614u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x100618: 0xc045188  jal         func_114620
    ctx->pc = 0x100618u;
    SET_GPR_U32(ctx, 31, 0x100620u);
    ctx->pc = 0x10061Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x100618u;
            // 0x10061c: 0xafa00008  sw          $zero, 0x8($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114620u;
    if (runtime->hasFunction(0x114620u)) {
        auto targetFn = runtime->lookupFunction(0x114620u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100620u; }
        if (ctx->pc != 0x100620u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114620_0x114620(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100620u; }
        if (ctx->pc != 0x100620u) { return; }
    }
    ctx->pc = 0x100620u;
label_100620:
    // 0x100620: 0x3c030020  lui         $v1, 0x20
    ctx->pc = 0x100620u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)32 << 16));
    // 0x100624: 0xac627920  sw          $v0, 0x7920($v1)
    ctx->pc = 0x100624u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 31008), GPR_U32(ctx, 2));
    // 0x100628: 0x3c020020  lui         $v0, 0x20
    ctx->pc = 0x100628u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32 << 16));
    // 0x10062c: 0xac407934  sw          $zero, 0x7934($v0)
    ctx->pc = 0x10062cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 31028), GPR_U32(ctx, 0));
    // 0x100630: 0xdfbf0050  ld          $ra, 0x50($sp)
    ctx->pc = 0x100630u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 80)));
label_100634:
    // 0x100634: 0xdfb20040  ld          $s2, 0x40($sp)
    ctx->pc = 0x100634u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x100638: 0xdfb10030  ld          $s1, 0x30($sp)
    ctx->pc = 0x100638u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x10063c: 0xdfb00020  ld          $s0, 0x20($sp)
    ctx->pc = 0x10063cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x100640: 0x3e00008  jr          $ra
    ctx->pc = 0x100640u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x100644u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x100640u;
            // 0x100644: 0x27bd0060  addiu       $sp, $sp, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1005D8u: goto label_1005d8;
            case 0x1005DCu: goto label_1005dc;
            case 0x1005E4u: goto label_1005e4;
            case 0x1005F8u: goto label_1005f8;
            case 0x100604u: goto label_100604;
            case 0x100610u: goto label_100610;
            case 0x100620u: goto label_100620;
            case 0x100634u: goto label_100634;
            default: break;
        }
        return;
    }
    ctx->pc = 0x100648u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
