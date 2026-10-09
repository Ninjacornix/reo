#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00100298
// Address: 0x100298 - 0x100338
void sub_00100298_0x100298(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00100298_0x100298");
#endif

    switch (ctx->pc) {
        case 0x1002ecu: goto label_1002ec;
        case 0x100314u: goto label_100314;
        default: break;
    }

    ctx->pc = 0x100298u;

    // 0x100298: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x100298u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x10029c: 0x2405000b  addiu       $a1, $zero, 0xB
    ctx->pc = 0x10029cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 11));
    // 0x1002a0: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1002a0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1002a4: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1002a4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1002a8: 0x3c100020  lui         $s0, 0x20
    ctx->pc = 0x1002a8u;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)32 << 16));
    // 0x1002ac: 0x8c830000  lw          $v1, 0x0($a0)
    ctx->pc = 0x1002acu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1002b0: 0x3c040020  lui         $a0, 0x20
    ctx->pc = 0x1002b0u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)32 << 16));
    // 0x1002b4: 0xae037958  sw          $v1, 0x7958($s0)
    ctx->pc = 0x1002b4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 31064), GPR_U32(ctx, 3));
    // 0x1002b8: 0x8e027958  lw          $v0, 0x7958($s0)
    ctx->pc = 0x1002b8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 31064)));
    // 0x1002bc: 0xac82795c  sw          $v0, 0x795C($a0)
    ctx->pc = 0x1002bcu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 31068), GPR_U32(ctx, 2));
    // 0x1002c0: 0x8e037958  lw          $v1, 0x7958($s0)
    ctx->pc = 0x1002c0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 31064)));
    // 0x1002c4: 0x14650006  bne         $v1, $a1, . + 4 + (0x6 << 2)
    ctx->pc = 0x1002C4u;
    {
        const bool branch_taken_0x1002c4 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 5));
        ctx->pc = 0x1002C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1002C4u;
            // 0x1002c8: 0x3c020020  lui         $v0, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1002c4) {
            ctx->pc = 0x1002E0u;
            goto label_1002e0;
        }
    }
    ctx->pc = 0x1002CCu;
    // 0x1002cc: 0xae007958  sw          $zero, 0x7958($s0)
    ctx->pc = 0x1002ccu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 31064), GPR_U32(ctx, 0));
    // 0x1002d0: 0x3c020020  lui         $v0, 0x20
    ctx->pc = 0x1002d0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32 << 16));
    // 0x1002d4: 0xac407934  sw          $zero, 0x7934($v0)
    ctx->pc = 0x1002d4u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 31028), GPR_U32(ctx, 0));
    // 0x1002d8: 0x10000014  b           . + 4 + (0x14 << 2)
    ctx->pc = 0x1002D8u;
    {
        const bool branch_taken_0x1002d8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1002DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1002D8u;
            // 0x1002dc: 0xdfbf0010  ld          $ra, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1002d8) {
            ctx->pc = 0x10032Cu;
            goto label_10032c;
        }
    }
    ctx->pc = 0x1002E0u;
label_1002e0:
    // 0x1002e0: 0x8c447928  lw          $a0, 0x7928($v0)
    ctx->pc = 0x1002e0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 31016)));
    // 0x1002e4: 0xc045194  jal         func_114650
    ctx->pc = 0x1002E4u;
    SET_GPR_U32(ctx, 31, 0x1002ECu);
    ctx->pc = 0x114650u;
    if (runtime->hasFunction(0x114650u)) {
        auto targetFn = runtime->lookupFunction(0x114650u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1002ECu; }
        if (ctx->pc != 0x1002ECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114650_0x114650(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1002ECu; }
        if (ctx->pc != 0x1002ECu) { return; }
    }
    ctx->pc = 0x1002ECu;
label_1002ec:
    // 0x1002ec: 0x3c030020  lui         $v1, 0x20
    ctx->pc = 0x1002ecu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)32 << 16));
    // 0x1002f0: 0x8c627914  lw          $v0, 0x7914($v1)
    ctx->pc = 0x1002f0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 30996)));
    // 0x1002f4: 0x10400009  beqz        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1002F4u;
    {
        const bool branch_taken_0x1002f4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1002F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1002F4u;
            // 0x1002f8: 0x3c020026  lui         $v0, 0x26 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1002f4) {
            ctx->pc = 0x10031Cu;
            goto label_10031c;
        }
    }
    ctx->pc = 0x1002FCu;
    // 0x1002fc: 0x8c439f80  lw          $v1, -0x6080($v0)
    ctx->pc = 0x1002fcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294942592)));
    // 0x100300: 0x10600006  beqz        $v1, . + 4 + (0x6 << 2)
    ctx->pc = 0x100300u;
    {
        const bool branch_taken_0x100300 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x100304u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x100300u;
            // 0x100304: 0x3c020020  lui         $v0, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x100300) {
            ctx->pc = 0x10031Cu;
            goto label_10031c;
        }
    }
    ctx->pc = 0x100308u;
    // 0x100308: 0x8c447920  lw          $a0, 0x7920($v0)
    ctx->pc = 0x100308u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 31008)));
    // 0x10030c: 0xc045194  jal         func_114650
    ctx->pc = 0x10030Cu;
    SET_GPR_U32(ctx, 31, 0x100314u);
    ctx->pc = 0x114650u;
    if (runtime->hasFunction(0x114650u)) {
        auto targetFn = runtime->lookupFunction(0x114650u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100314u; }
        if (ctx->pc != 0x100314u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114650_0x114650(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100314u; }
        if (ctx->pc != 0x100314u) { return; }
    }
    ctx->pc = 0x100314u;
label_100314:
    // 0x100314: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x100314u;
    {
        const bool branch_taken_0x100314 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x100314) {
            ctx->pc = 0x100324u;
            goto label_100324;
        }
    }
    ctx->pc = 0x10031Cu;
label_10031c:
    // 0x10031c: 0x3c020020  lui         $v0, 0x20
    ctx->pc = 0x10031cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32 << 16));
    // 0x100320: 0xac407934  sw          $zero, 0x7934($v0)
    ctx->pc = 0x100320u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 31028), GPR_U32(ctx, 0));
label_100324:
    // 0x100324: 0xae007958  sw          $zero, 0x7958($s0)
    ctx->pc = 0x100324u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 31064), GPR_U32(ctx, 0));
    // 0x100328: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x100328u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_10032c:
    // 0x10032c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x10032cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x100330: 0x3e00008  jr          $ra
    ctx->pc = 0x100330u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x100334u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x100330u;
            // 0x100334: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1002E0u: goto label_1002e0;
            case 0x1002ECu: goto label_1002ec;
            case 0x100314u: goto label_100314;
            case 0x10031Cu: goto label_10031c;
            case 0x100324u: goto label_100324;
            case 0x10032Cu: goto label_10032c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x100338u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
