#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0011F228
// Address: 0x11f228 - 0x11f2d8
void sub_0011F228_0x11f228(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0011F228_0x11f228");
#endif

    switch (ctx->pc) {
        case 0x11f248u: goto label_11f248;
        case 0x11f2a4u: goto label_11f2a4;
        default: break;
    }

    ctx->pc = 0x11f228u;

    // 0x11f228: 0x3c050026  lui         $a1, 0x26
    ctx->pc = 0x11f228u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)38 << 16));
    // 0x11f22c: 0x3c030026  lui         $v1, 0x26
    ctx->pc = 0x11f22cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)38 << 16));
    // 0x11f230: 0x24a21900  addiu       $v0, $a1, 0x1900
    ctx->pc = 0x11f230u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 5), 6400));
    // 0x11f234: 0x2404003f  addiu       $a0, $zero, 0x3F
    ctx->pc = 0x11f234u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 63));
    // 0x11f238: 0xac621d00  sw          $v0, 0x1D00($v1)
    ctx->pc = 0x11f238u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 7424), GPR_U32(ctx, 2));
    // 0x11f23c: 0x24430400  addiu       $v1, $v0, 0x400
    ctx->pc = 0x11f23cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 1024));
    // 0x11f240: 0x244203f0  addiu       $v0, $v0, 0x3F0
    ctx->pc = 0x11f240u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1008));
    // 0x11f244: 0x0  nop
    ctx->pc = 0x11f244u;
    // NOP
label_11f248:
    // 0x11f248: 0xac430000  sw          $v1, 0x0($v0)
    ctx->pc = 0x11f248u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
    // 0x11f24c: 0x2484ffff  addiu       $a0, $a0, -0x1
    ctx->pc = 0x11f24cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967295));
    // 0x11f250: 0x2442fff0  addiu       $v0, $v0, -0x10
    ctx->pc = 0x11f250u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967280));
    // 0x11f254: 0x2463fff0  addiu       $v1, $v1, -0x10
    ctx->pc = 0x11f254u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967280));
    // 0x11f258: 0x0  nop
    ctx->pc = 0x11f258u;
    // NOP
    // 0x11f25c: 0x481fffa  bgez        $a0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x11F25Cu;
    {
        const bool branch_taken_0x11f25c = (GPR_S64(ctx, 4) >= 0);
        if (branch_taken_0x11f25c) {
            ctx->pc = 0x11F248u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_11f248;
        }
    }
    ctx->pc = 0x11F264u;
    // 0x11f264: 0x24a31900  addiu       $v1, $a1, 0x1900
    ctx->pc = 0x11f264u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 5), 6400));
    // 0x11f268: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x11f268u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11f26c: 0x3e00008  jr          $ra
    ctx->pc = 0x11F26Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11F270u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11F26Cu;
            // 0x11f270: 0xac6003f0  sw          $zero, 0x3F0($v1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 3), 1008), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11F248u: goto label_11f248;
            case 0x11F2A4u: goto label_11f2a4;
            case 0x11F2C8u: goto label_11f2c8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11F274u;
    // 0x11f274: 0x0  nop
    ctx->pc = 0x11f274u;
    // NOP
    // 0x11f278: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x11f278u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x11f27c: 0x308400fe  andi        $a0, $a0, 0xFE
    ctx->pc = 0x11f27cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)254);
    // 0x11f280: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x11f280u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x11f284: 0xe0802d  daddu       $s0, $a3, $zero
    ctx->pc = 0x11f284u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11f288: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x11f288u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x11f28c: 0x101900  sll         $v1, $s0, 4
    ctx->pc = 0x11f28cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 16), 4));
    // 0x11f290: 0x641825  or          $v1, $v1, $a0
    ctx->pc = 0x11f290u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 4));
    // 0x11f294: 0x8e020008  lw          $v0, 0x8($s0)
    ctx->pc = 0x11f294u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x11f298: 0x8e07000c  lw          $a3, 0xC($s0)
    ctx->pc = 0x11f298u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x11f29c: 0x40f809  jalr        $v0
    ctx->pc = 0x11F29Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x11F2A4u);
        ctx->pc = 0x11F2A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11F29Cu;
            // 0x11f2a0: 0x34640001  ori         $a0, $v1, 0x1 (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)1);
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x11F2A4u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11F248u: goto label_11f248;
            case 0x11F2A4u: goto label_11f2a4;
            case 0x11F2C8u: goto label_11f2c8;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x11F2A4u; }
            if (ctx->pc != 0x11F2A4u) { return; }
        }
        }
    }
    ctx->pc = 0x11F2A4u;
label_11f2a4:
    // 0x11f2a4: 0x14400008  bnez        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x11F2A4u;
    {
        const bool branch_taken_0x11f2a4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x11F2A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11F2A4u;
            // 0x11f2a8: 0xdfbf0010  ld          $ra, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11f2a4) {
            ctx->pc = 0x11F2C8u;
            goto label_11f2c8;
        }
    }
    ctx->pc = 0x11F2ACu;
    // 0x11f2ac: 0x3c030026  lui         $v1, 0x26
    ctx->pc = 0x11f2acu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)38 << 16));
    // 0x11f2b0: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x11f2b0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x11f2b4: 0x8c641d00  lw          $a0, 0x1D00($v1)
    ctx->pc = 0x11f2b4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 7424)));
    // 0x11f2b8: 0xac701d00  sw          $s0, 0x1D00($v1)
    ctx->pc = 0x11f2b8u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 7424), GPR_U32(ctx, 16));
    // 0x11f2bc: 0xae040000  sw          $a0, 0x0($s0)
    ctx->pc = 0x11f2bcu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 4));
    // 0x11f2c0: 0xae000004  sw          $zero, 0x4($s0)
    ctx->pc = 0x11f2c0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 0));
    // 0x11f2c4: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x11f2c4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_11f2c8:
    // 0x11f2c8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x11f2c8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x11f2cc: 0x3e00008  jr          $ra
    ctx->pc = 0x11F2CCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11F2D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11F2CCu;
            // 0x11f2d0: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11F248u: goto label_11f248;
            case 0x11F2A4u: goto label_11f2a4;
            case 0x11F2C8u: goto label_11f2c8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11F2D4u;
    // 0x11f2d4: 0x0  nop
    ctx->pc = 0x11f2d4u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
