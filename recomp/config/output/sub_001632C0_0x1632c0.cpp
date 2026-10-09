#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001632C0
// Address: 0x1632c0 - 0x163370
void sub_001632C0_0x1632c0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001632C0_0x1632c0");
#endif

    switch (ctx->pc) {
        case 0x1632e4u: goto label_1632e4;
        case 0x1632f8u: goto label_1632f8;
        case 0x163314u: goto label_163314;
        case 0x163324u: goto label_163324;
        default: break;
    }

    ctx->pc = 0x1632c0u;

    // 0x1632c0: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1632c0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1632c4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1632c4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1632c8: 0x249001ec  addiu       $s0, $a0, 0x1EC
    ctx->pc = 0x1632c8u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 4), 492));
    // 0x1632cc: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x1632ccu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x1632d0: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x1632d0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x1632d4: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x1632d4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x1632d8: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1632d8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1632dc: 0xc058d08  jal         func_163420
    ctx->pc = 0x1632DCu;
    SET_GPR_U32(ctx, 31, 0x1632E4u);
    ctx->pc = 0x1632E0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1632DCu;
            // 0x1632e0: 0x8c930040  lw          $s3, 0x40($a0) (Delay Slot)
        SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 64)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163420u;
    if (runtime->hasFunction(0x163420u)) {
        auto targetFn = runtime->lookupFunction(0x163420u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1632E4u; }
        if (ctx->pc != 0x1632E4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163420_0x163420(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1632E4u; }
        if (ctx->pc != 0x1632E4u) { return; }
    }
    ctx->pc = 0x1632E4u;
label_1632e4:
    // 0x1632e4: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1632e4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1632e8: 0x8e120014  lw          $s2, 0x14($s0)
    ctx->pc = 0x1632e8u;
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
    // 0x1632ec: 0x8e11000c  lw          $s1, 0xC($s0)
    ctx->pc = 0x1632ecu;
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x1632f0: 0xc058d10  jal         func_163440
    ctx->pc = 0x1632F0u;
    SET_GPR_U32(ctx, 31, 0x1632F8u);
    ctx->pc = 0x1632F4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1632F0u;
            // 0x1632f4: 0x8e100010  lw          $s0, 0x10($s0) (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 16)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163440u;
    if (runtime->hasFunction(0x163440u)) {
        auto targetFn = runtime->lookupFunction(0x163440u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1632F8u; }
        if (ctx->pc != 0x1632F8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163440_0x163440(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1632F8u; }
        if (ctx->pc != 0x1632F8u) { return; }
    }
    ctx->pc = 0x1632F8u;
label_1632f8:
    // 0x1632f8: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1632f8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1632fc: 0x54430016  bnel        $v0, $v1, . + 4 + (0x16 << 2)
    ctx->pc = 0x1632FCu;
    {
        const bool branch_taken_0x1632fc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        if (branch_taken_0x1632fc) {
            ctx->pc = 0x163300u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1632FCu;
            // 0x163300: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x163358u;
            goto label_163358;
        }
    }
    ctx->pc = 0x163304u;
    // 0x163304: 0x52400004  beql        $s2, $zero, . + 4 + (0x4 << 2)
    ctx->pc = 0x163304u;
    {
        const bool branch_taken_0x163304 = (GPR_U64(ctx, 18) == GPR_U64(ctx, 0));
        if (branch_taken_0x163304) {
            ctx->pc = 0x163308u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x163304u;
            // 0x163308: 0x8e230000  lw          $v1, 0x0($s1) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x163318u;
            goto label_163318;
        }
    }
    ctx->pc = 0x16330Cu;
    // 0x16330c: 0xc058bd2  jal         func_162F48
    ctx->pc = 0x16330Cu;
    SET_GPR_U32(ctx, 31, 0x163314u);
    ctx->pc = 0x163310u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16330Cu;
            // 0x163310: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x162F48u;
    if (runtime->hasFunction(0x162F48u)) {
        auto targetFn = runtime->lookupFunction(0x162F48u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x163314u; }
        if (ctx->pc != 0x163314u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00162F48_0x162f48(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x163314u; }
        if (ctx->pc != 0x163314u) { return; }
    }
    ctx->pc = 0x163314u;
label_163314:
    // 0x163314: 0x8e230000  lw          $v1, 0x0($s1)
    ctx->pc = 0x163314u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
label_163318:
    // 0x163318: 0x8c620014  lw          $v0, 0x14($v1)
    ctx->pc = 0x163318u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 20)));
    // 0x16331c: 0x40f809  jalr        $v0
    ctx->pc = 0x16331Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x163324u);
        ctx->pc = 0x163320u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16331Cu;
            // 0x163320: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x163324u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1632E4u: goto label_1632e4;
            case 0x1632F8u: goto label_1632f8;
            case 0x163314u: goto label_163314;
            case 0x163318u: goto label_163318;
            case 0x163324u: goto label_163324;
            case 0x163358u: goto label_163358;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x163324u; }
            if (ctx->pc != 0x163324u) { return; }
        }
        }
    }
    ctx->pc = 0x163324u;
label_163324:
    // 0x163324: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x163324u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x163328: 0x260500c0  addiu       $a1, $s0, 0xC0
    ctx->pc = 0x163328u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), 192));
    // 0x16332c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x16332cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x163330: 0x220302d  daddu       $a2, $s1, $zero
    ctx->pc = 0x163330u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x163334: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x163334u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x163338: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x163338u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x16333c: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x16333cu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x163340: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x163340u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x163344: 0x402d  daddu       $t0, $zero, $zero
    ctx->pc = 0x163344u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x163348: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x163348u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x16334c: 0x805a7fc  j           func_169FF0
    ctx->pc = 0x16334Cu;
    ctx->pc = 0x163350u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16334Cu;
            // 0x163350: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169FF0u;
    if (runtime->hasFunction(0x169FF0u)) {
        auto targetFn = runtime->lookupFunction(0x169FF0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00169FF0_0x169ff0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x163354u;
    // 0x163354: 0x0  nop
    ctx->pc = 0x163354u;
    // NOP
label_163358:
    // 0x163358: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x163358u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x16335c: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x16335cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x163360: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x163360u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x163364: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x163364u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x163368: 0x3e00008  jr          $ra
    ctx->pc = 0x163368u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x16336Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x163368u;
            // 0x16336c: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1632E4u: goto label_1632e4;
            case 0x1632F8u: goto label_1632f8;
            case 0x163314u: goto label_163314;
            case 0x163318u: goto label_163318;
            case 0x163324u: goto label_163324;
            case 0x163358u: goto label_163358;
            default: break;
        }
        return;
    }
    ctx->pc = 0x163370u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
