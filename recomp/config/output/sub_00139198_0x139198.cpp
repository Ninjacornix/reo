#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00139198
// Address: 0x139198 - 0x1392f8
void sub_00139198_0x139198(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00139198_0x139198");
#endif

    switch (ctx->pc) {
        case 0x1391fcu: goto label_1391fc;
        case 0x139210u: goto label_139210;
        case 0x139264u: goto label_139264;
        case 0x139290u: goto label_139290;
        case 0x1392a8u: goto label_1392a8;
        case 0x1392dcu: goto label_1392dc;
        default: break;
    }

    ctx->pc = 0x139198u;

    // 0x139198: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x139198u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x13919c: 0x3c030022  lui         $v1, 0x22
    ctx->pc = 0x13919cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)34 << 16));
    // 0x1391a0: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1391a0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1391a4: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1391a4u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1391a8: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x1391a8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x1391ac: 0x2463c428  addiu       $v1, $v1, -0x3BD8
    ctx->pc = 0x1391acu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294951976));
    // 0x1391b0: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1391b0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1391b4: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x1391b4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1391b8: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x1391b8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1391bc: 0x82050001  lb          $a1, 0x1($s0)
    ctx->pc = 0x1391bcu;
    SET_GPR_S32(ctx, 5, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 1)));
    // 0x1391c0: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1391c0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1391c4: 0x14a40016  bne         $a1, $a0, . + 4 + (0x16 << 2)
    ctx->pc = 0x1391C4u;
    {
        const bool branch_taken_0x1391c4 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 4));
        ctx->pc = 0x1391C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1391C4u;
            // 0x1391c8: 0xac620000  sw          $v0, 0x0($v1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1391c4) {
            ctx->pc = 0x139220u;
            goto label_139220;
        }
    }
    ctx->pc = 0x1391CCu;
    // 0x1391cc: 0x8e020014  lw          $v0, 0x14($s0)
    ctx->pc = 0x1391ccu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
    // 0x1391d0: 0x8e030008  lw          $v1, 0x8($s0)
    ctx->pc = 0x1391d0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x1391d4: 0x8c44003c  lw          $a0, 0x3C($v0)
    ctx->pc = 0x1391d4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 60)));
    // 0x1391d8: 0x64182a  slt         $v1, $v1, $a0
    ctx->pc = 0x1391d8u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 3) < (int64_t)GPR_S64(ctx, 4)) ? 1 : 0);
    // 0x1391dc: 0x50600011  beql        $v1, $zero, . + 4 + (0x11 << 2)
    ctx->pc = 0x1391DCu;
    {
        const bool branch_taken_0x1391dc = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x1391dc) {
            ctx->pc = 0x1391E0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1391DCu;
            // 0x1391e0: 0x8e020000  lw          $v0, 0x0($s0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x139224u;
            goto label_139224;
        }
    }
    ctx->pc = 0x1391E4u;
    // 0x1391e4: 0x8e020010  lw          $v0, 0x10($s0)
    ctx->pc = 0x1391e4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 16)));
    // 0x1391e8: 0x8e05000c  lw          $a1, 0xC($s0)
    ctx->pc = 0x1391e8u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x1391ec: 0xa0202d  daddu       $a0, $a1, $zero
    ctx->pc = 0x1391ecu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1391f0: 0xa22821  addu        $a1, $a1, $v0
    ctx->pc = 0x1391f0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
    // 0x1391f4: 0xc045416  jal         func_115058
    ctx->pc = 0x1391F4u;
    SET_GPR_U32(ctx, 31, 0x1391FCu);
    ctx->pc = 0x1391F8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1391F4u;
            // 0x1391f8: 0x24a5ffff  addiu       $a1, $a1, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967295));
        ctx->in_delay_slot = false;
    ctx->pc = 0x115058u;
    if (runtime->hasFunction(0x115058u)) {
        auto targetFn = runtime->lookupFunction(0x115058u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1391FCu; }
        if (ctx->pc != 0x1391FCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00115058_0x115058(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1391FCu; }
        if (ctx->pc != 0x1391FCu) { return; }
    }
    ctx->pc = 0x1391FCu;
label_1391fc:
    // 0x1391fc: 0x8e030020  lw          $v1, 0x20($s0)
    ctx->pc = 0x1391fcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 32)));
    // 0x139200: 0x8e040024  lw          $a0, 0x24($s0)
    ctx->pc = 0x139200u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 36)));
    // 0x139204: 0x8e05000c  lw          $a1, 0xC($s0)
    ctx->pc = 0x139204u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x139208: 0x60f809  jalr        $v1
    ctx->pc = 0x139208u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        SET_GPR_U32(ctx, 31, 0x139210u);
        ctx->pc = 0x13920Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x139208u;
            // 0x13920c: 0x8e060010  lw          $a2, 0x10($s0) (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 16)));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x139210u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1391FCu: goto label_1391fc;
            case 0x139210u: goto label_139210;
            case 0x139220u: goto label_139220;
            case 0x139224u: goto label_139224;
            case 0x139264u: goto label_139264;
            case 0x139290u: goto label_139290;
            case 0x1392A8u: goto label_1392a8;
            case 0x1392DCu: goto label_1392dc;
            case 0x1392E8u: goto label_1392e8;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x139210u; }
            if (ctx->pc != 0x139210u) { return; }
        }
        }
    }
    ctx->pc = 0x139210u;
label_139210:
    // 0x139210: 0x8e020014  lw          $v0, 0x14($s0)
    ctx->pc = 0x139210u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
    // 0x139214: 0x8c43003c  lw          $v1, 0x3C($v0)
    ctx->pc = 0x139214u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 60)));
    // 0x139218: 0xa2000001  sb          $zero, 0x1($s0)
    ctx->pc = 0x139218u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 1), (uint8_t)GPR_U32(ctx, 0));
    // 0x13921c: 0xae030008  sw          $v1, 0x8($s0)
    ctx->pc = 0x13921cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 8), GPR_U32(ctx, 3));
label_139220:
    // 0x139220: 0x8e020000  lw          $v0, 0x0($s0)
    ctx->pc = 0x139220u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
label_139224:
    // 0x139224: 0x3c0300ff  lui         $v1, 0xFF
    ctx->pc = 0x139224u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)255 << 16));
    // 0x139228: 0x3463ff00  ori         $v1, $v1, 0xFF00
    ctx->pc = 0x139228u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)65280);
    // 0x13922c: 0x3c040001  lui         $a0, 0x1
    ctx->pc = 0x13922cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)1 << 16));
    // 0x139230: 0x431024  and         $v0, $v0, $v1
    ctx->pc = 0x139230u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 3));
    // 0x139234: 0x5444002c  bnel        $v0, $a0, . + 4 + (0x2C << 2)
    ctx->pc = 0x139234u;
    {
        const bool branch_taken_0x139234 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 4));
        if (branch_taken_0x139234) {
            ctx->pc = 0x139238u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x139234u;
            // 0x139238: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1392E8u;
            goto label_1392e8;
        }
    }
    ctx->pc = 0x13923Cu;
    // 0x13923c: 0x3c020022  lui         $v0, 0x22
    ctx->pc = 0x13923cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)34 << 16));
    // 0x139240: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x139240u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x139244: 0x8c51c41c  lw          $s1, -0x3BE4($v0)
    ctx->pc = 0x139244u;
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294951964)));
    // 0x139248: 0x56230027  bnel        $s1, $v1, . + 4 + (0x27 << 2)
    ctx->pc = 0x139248u;
    {
        const bool branch_taken_0x139248 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 3));
        if (branch_taken_0x139248) {
            ctx->pc = 0x13924Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x139248u;
            // 0x13924c: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1392E8u;
            goto label_1392e8;
        }
    }
    ctx->pc = 0x139250u;
    // 0x139250: 0x8e060010  lw          $a2, 0x10($s0)
    ctx->pc = 0x139250u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 16)));
    // 0x139254: 0x8e04002c  lw          $a0, 0x2C($s0)
    ctx->pc = 0x139254u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 44)));
    // 0x139258: 0x8e020028  lw          $v0, 0x28($s0)
    ctx->pc = 0x139258u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 40)));
    // 0x13925c: 0x40f809  jalr        $v0
    ctx->pc = 0x13925Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x139264u);
        ctx->pc = 0x139260u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13925Cu;
            // 0x139260: 0x8e05000c  lw          $a1, 0xC($s0) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x139264u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1391FCu: goto label_1391fc;
            case 0x139210u: goto label_139210;
            case 0x139220u: goto label_139220;
            case 0x139224u: goto label_139224;
            case 0x139264u: goto label_139264;
            case 0x139290u: goto label_139290;
            case 0x1392A8u: goto label_1392a8;
            case 0x1392DCu: goto label_1392dc;
            case 0x1392E8u: goto label_1392e8;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x139264u; }
            if (ctx->pc != 0x139264u) { return; }
        }
        }
    }
    ctx->pc = 0x139264u;
label_139264:
    // 0x139264: 0x8e030008  lw          $v1, 0x8($s0)
    ctx->pc = 0x139264u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x139268: 0x8e020014  lw          $v0, 0x14($s0)
    ctx->pc = 0x139268u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
    // 0x13926c: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x13926cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x139270: 0x8e05000c  lw          $a1, 0xC($s0)
    ctx->pc = 0x139270u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x139274: 0xae030008  sw          $v1, 0x8($s0)
    ctx->pc = 0x139274u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 8), GPR_U32(ctx, 3));
    // 0x139278: 0xac43003c  sw          $v1, 0x3C($v0)
    ctx->pc = 0x139278u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 60), GPR_U32(ctx, 3));
    // 0x13927c: 0xa0202d  daddu       $a0, $a1, $zero
    ctx->pc = 0x13927cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x139280: 0x8e020010  lw          $v0, 0x10($s0)
    ctx->pc = 0x139280u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 16)));
    // 0x139284: 0xa22821  addu        $a1, $a1, $v0
    ctx->pc = 0x139284u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
    // 0x139288: 0xc0453c6  jal         func_114F18
    ctx->pc = 0x139288u;
    SET_GPR_U32(ctx, 31, 0x139290u);
    ctx->pc = 0x13928Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x139288u;
            // 0x13928c: 0x24a5ffff  addiu       $a1, $a1, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967295));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114F18u;
    if (runtime->hasFunction(0x114F18u)) {
        auto targetFn = runtime->lookupFunction(0x114F18u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x139290u; }
        if (ctx->pc != 0x139290u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114F18_0x114f18(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x139290u; }
        if (ctx->pc != 0x139290u) { return; }
    }
    ctx->pc = 0x139290u;
label_139290:
    // 0x139290: 0x8e05000c  lw          $a1, 0xC($s0)
    ctx->pc = 0x139290u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x139294: 0x8e020010  lw          $v0, 0x10($s0)
    ctx->pc = 0x139294u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 16)));
    // 0x139298: 0xa0202d  daddu       $a0, $a1, $zero
    ctx->pc = 0x139298u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13929c: 0xa22821  addu        $a1, $a1, $v0
    ctx->pc = 0x13929cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
    // 0x1392a0: 0xc045416  jal         func_115058
    ctx->pc = 0x1392A0u;
    SET_GPR_U32(ctx, 31, 0x1392A8u);
    ctx->pc = 0x1392A4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1392A0u;
            // 0x1392a4: 0x24a5003f  addiu       $a1, $a1, 0x3F (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 63));
        ctx->in_delay_slot = false;
    ctx->pc = 0x115058u;
    if (runtime->hasFunction(0x115058u)) {
        auto targetFn = runtime->lookupFunction(0x115058u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1392A8u; }
        if (ctx->pc != 0x1392A8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00115058_0x115058(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1392A8u; }
        if (ctx->pc != 0x1392A8u) { return; }
    }
    ctx->pc = 0x1392A8u;
label_1392a8:
    // 0x1392a8: 0x8e03000c  lw          $v1, 0xC($s0)
    ctx->pc = 0x1392a8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x1392ac: 0x3c020fff  lui         $v0, 0xFFF
    ctx->pc = 0x1392acu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)4095 << 16));
    // 0x1392b0: 0x8e040018  lw          $a0, 0x18($s0)
    ctx->pc = 0x1392b0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 24)));
    // 0x1392b4: 0x8e05001c  lw          $a1, 0x1C($s0)
    ctx->pc = 0x1392b4u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 28)));
    // 0x1392b8: 0x3442ffff  ori         $v0, $v0, 0xFFFF
    ctx->pc = 0x1392b8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65535);
    // 0x1392bc: 0x621824  and         $v1, $v1, $v0
    ctx->pc = 0x1392bcu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1392c0: 0xae040034  sw          $a0, 0x34($s0)
    ctx->pc = 0x1392c0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 52), GPR_U32(ctx, 4));
    // 0x1392c4: 0xae050038  sw          $a1, 0x38($s0)
    ctx->pc = 0x1392c4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 56), GPR_U32(ctx, 5));
    // 0x1392c8: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x1392c8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1392cc: 0xae030030  sw          $v1, 0x30($s0)
    ctx->pc = 0x1392ccu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 48), GPR_U32(ctx, 3));
    // 0x1392d0: 0x26040030  addiu       $a0, $s0, 0x30
    ctx->pc = 0x1392d0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 48));
    // 0x1392d4: 0xc045278  jal         func_1149E0
    ctx->pc = 0x1392D4u;
    SET_GPR_U32(ctx, 31, 0x1392DCu);
    ctx->pc = 0x1392D8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1392D4u;
            // 0x1392d8: 0xae00003c  sw          $zero, 0x3C($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 60), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1149E0u;
    if (runtime->hasFunction(0x1149E0u)) {
        auto targetFn = runtime->lookupFunction(0x1149E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1392DCu; }
        if (ctx->pc != 0x1392DCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001149E0_0x1149e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1392DCu; }
        if (ctx->pc != 0x1392DCu) { return; }
    }
    ctx->pc = 0x1392DCu;
label_1392dc:
    // 0x1392dc: 0xa2110001  sb          $s1, 0x1($s0)
    ctx->pc = 0x1392dcu;
    WRITE8(ADD32(GPR_U32(ctx, 16), 1), (uint8_t)GPR_U32(ctx, 17));
    // 0x1392e0: 0xae020040  sw          $v0, 0x40($s0)
    ctx->pc = 0x1392e0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 64), GPR_U32(ctx, 2));
    // 0x1392e4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1392e4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_1392e8:
    // 0x1392e8: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1392e8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1392ec: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1392ecu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1392f0: 0x3e00008  jr          $ra
    ctx->pc = 0x1392F0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1392F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1392F0u;
            // 0x1392f4: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1391FCu: goto label_1391fc;
            case 0x139210u: goto label_139210;
            case 0x139220u: goto label_139220;
            case 0x139224u: goto label_139224;
            case 0x139264u: goto label_139264;
            case 0x139290u: goto label_139290;
            case 0x1392A8u: goto label_1392a8;
            case 0x1392DCu: goto label_1392dc;
            case 0x1392E8u: goto label_1392e8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1392F8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
