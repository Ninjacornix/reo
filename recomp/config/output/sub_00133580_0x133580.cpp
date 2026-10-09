#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00133580
// Address: 0x133580 - 0x133618
void sub_00133580_0x133580(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00133580_0x133580");
#endif

    switch (ctx->pc) {
        case 0x1335c8u: goto label_1335c8;
        case 0x1335d4u: goto label_1335d4;
        default: break;
    }

    ctx->pc = 0x133580u;

    // 0x133580: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x133580u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x133584: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x133584u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x133588: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x133588u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13358c: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x13358cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x133590: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x133590u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x133594: 0x12000003  beqz        $s0, . + 4 + (0x3 << 2)
    ctx->pc = 0x133594u;
    {
        const bool branch_taken_0x133594 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        ctx->pc = 0x133598u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x133594u;
            // 0x133598: 0xffbf0010  sd          $ra, 0x10($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x133594) {
            ctx->pc = 0x1335A4u;
            goto label_1335a4;
        }
    }
    ctx->pc = 0x13359Cu;
    // 0x13359c: 0x16200008  bnez        $s1, . + 4 + (0x8 << 2)
    ctx->pc = 0x13359Cu;
    {
        const bool branch_taken_0x13359c = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        if (branch_taken_0x13359c) {
            ctx->pc = 0x1335C0u;
            goto label_1335c0;
        }
    }
    ctx->pc = 0x1335A4u;
label_1335a4:
    // 0x1335a4: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x1335a4u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x1335a8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1335a8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1335ac: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1335acu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1335b0: 0x2484b5d0  addiu       $a0, $a0, -0x4A30
    ctx->pc = 0x1335b0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294948304));
    // 0x1335b4: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1335b4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1335b8: 0x804a034  j           func_1280D0
    ctx->pc = 0x1335B8u;
    ctx->pc = 0x1335BCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1335B8u;
            // 0x1335bc: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1280D0u;
    if (runtime->hasFunction(0x1280D0u)) {
        auto targetFn = runtime->lookupFunction(0x1280D0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001280D0_0x1280d0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1335C0u;
label_1335c0:
    // 0x1335c0: 0xc04c78e  jal         func_131E38
    ctx->pc = 0x1335C0u;
    SET_GPR_U32(ctx, 31, 0x1335C8u);
    ctx->pc = 0x131E38u;
    if (runtime->hasFunction(0x131E38u)) {
        auto targetFn = runtime->lookupFunction(0x131E38u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1335C8u; }
        if (ctx->pc != 0x1335C8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00131E38_0x131e38(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1335C8u; }
        if (ctx->pc != 0x1335C8u) { return; }
    }
    ctx->pc = 0x1335C8u;
label_1335c8:
    // 0x1335c8: 0x8e0400b0  lw          $a0, 0xB0($s0)
    ctx->pc = 0x1335c8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 176)));
    // 0x1335cc: 0xc042bf0  jal         func_10AFC0
    ctx->pc = 0x1335CCu;
    SET_GPR_U32(ctx, 31, 0x1335D4u);
    ctx->pc = 0x1335D0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1335CCu;
            // 0x1335d0: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10AFC0u;
    if (runtime->hasFunction(0x10AFC0u)) {
        auto targetFn = runtime->lookupFunction(0x10AFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1335D4u; }
        if (ctx->pc != 0x1335D4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AFC0_0x10afc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1335D4u; }
        if (ctx->pc != 0x1335D4u) { return; }
    }
    ctx->pc = 0x1335D4u;
label_1335d4:
    // 0x1335d4: 0x8e0300b0  lw          $v1, 0xB0($s0)
    ctx->pc = 0x1335d4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 176)));
    // 0x1335d8: 0x3c02000f  lui         $v0, 0xF
    ctx->pc = 0x1335d8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)15 << 16));
    // 0x1335dc: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x1335dcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1335e0: 0x3442ffff  ori         $v0, $v0, 0xFFFF
    ctx->pc = 0x1335e0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65535);
    // 0x1335e4: 0xae0300b4  sw          $v1, 0xB4($s0)
    ctx->pc = 0x1335e4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 180), GPR_U32(ctx, 3));
    // 0x1335e8: 0xae0200c0  sw          $v0, 0xC0($s0)
    ctx->pc = 0x1335e8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 192), GPR_U32(ctx, 2));
    // 0x1335ec: 0xa20400ac  sb          $a0, 0xAC($s0)
    ctx->pc = 0x1335ecu;
    WRITE8(ADD32(GPR_U32(ctx, 16), 172), (uint8_t)GPR_U32(ctx, 4));
    // 0x1335f0: 0xa2000098  sb          $zero, 0x98($s0)
    ctx->pc = 0x1335f0u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 152), (uint8_t)GPR_U32(ctx, 0));
    // 0x1335f4: 0xae0000b8  sw          $zero, 0xB8($s0)
    ctx->pc = 0x1335f4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 184), GPR_U32(ctx, 0));
    // 0x1335f8: 0xae0000bc  sw          $zero, 0xBC($s0)
    ctx->pc = 0x1335f8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 188), GPR_U32(ctx, 0));
    // 0x1335fc: 0xa2040001  sb          $a0, 0x1($s0)
    ctx->pc = 0x1335fcu;
    WRITE8(ADD32(GPR_U32(ctx, 16), 1), (uint8_t)GPR_U32(ctx, 4));
    // 0x133600: 0xa2000002  sb          $zero, 0x2($s0)
    ctx->pc = 0x133600u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 2), (uint8_t)GPR_U32(ctx, 0));
    // 0x133604: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x133604u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x133608: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x133608u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13360c: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x13360cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x133610: 0x3e00008  jr          $ra
    ctx->pc = 0x133610u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x133614u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x133610u;
            // 0x133614: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1335A4u: goto label_1335a4;
            case 0x1335C0u: goto label_1335c0;
            case 0x1335C8u: goto label_1335c8;
            case 0x1335D4u: goto label_1335d4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x133618u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
