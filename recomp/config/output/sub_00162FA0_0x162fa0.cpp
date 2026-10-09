#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00162FA0
// Address: 0x162fa0 - 0x163078
void sub_00162FA0_0x162fa0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00162FA0_0x162fa0");
#endif

    switch (ctx->pc) {
        case 0x162fbcu: goto label_162fbc;
        case 0x162fd0u: goto label_162fd0;
        case 0x162fecu: goto label_162fec;
        case 0x16302cu: goto label_16302c;
        case 0x163040u: goto label_163040;
        case 0x16305cu: goto label_16305c;
        default: break;
    }

    ctx->pc = 0x162fa0u;

    // 0x162fa0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x162fa0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x162fa4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x162fa4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x162fa8: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x162fa8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x162fac: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x162facu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x162fb0: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x162fb0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x162fb4: 0xc058d10  jal         func_163440
    ctx->pc = 0x162FB4u;
    SET_GPR_U32(ctx, 31, 0x162FBCu);
    ctx->pc = 0x162FB8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x162FB4u;
            // 0x162fb8: 0x882d  daddu       $s1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163440u;
    if (runtime->hasFunction(0x163440u)) {
        auto targetFn = runtime->lookupFunction(0x163440u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x162FBCu; }
        if (ctx->pc != 0x162FBCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163440_0x163440(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x162FBCu; }
        if (ctx->pc != 0x162FBCu) { return; }
    }
    ctx->pc = 0x162FBCu;
label_162fbc:
    // 0x162fbc: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x162fbcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x162fc0: 0x1443000c  bne         $v0, $v1, . + 4 + (0xC << 2)
    ctx->pc = 0x162FC0u;
    {
        const bool branch_taken_0x162fc0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        ctx->pc = 0x162FC4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x162FC0u;
            // 0x162fc4: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x162fc0) {
            ctx->pc = 0x162FF4u;
            goto label_162ff4;
        }
    }
    ctx->pc = 0x162FC8u;
    // 0x162fc8: 0xc058d08  jal         func_163420
    ctx->pc = 0x162FC8u;
    SET_GPR_U32(ctx, 31, 0x162FD0u);
    ctx->pc = 0x163420u;
    if (runtime->hasFunction(0x163420u)) {
        auto targetFn = runtime->lookupFunction(0x163420u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x162FD0u; }
        if (ctx->pc != 0x162FD0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163420_0x163420(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x162FD0u; }
        if (ctx->pc != 0x162FD0u) { return; }
    }
    ctx->pc = 0x162FD0u;
label_162fd0:
    // 0x162fd0: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x162FD0u;
    {
        const bool branch_taken_0x162fd0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x162FD4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x162FD0u;
            // 0x162fd4: 0x8e040014  lw          $a0, 0x14($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x162fd0) {
            ctx->pc = 0x162FF0u;
            goto label_162ff0;
        }
    }
    ctx->pc = 0x162FD8u;
    // 0x162fd8: 0x8c42001c  lw          $v0, 0x1C($v0)
    ctx->pc = 0x162fd8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 28)));
    // 0x162fdc: 0x50400005  beql        $v0, $zero, . + 4 + (0x5 << 2)
    ctx->pc = 0x162FDCu;
    {
        const bool branch_taken_0x162fdc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x162fdc) {
            ctx->pc = 0x162FE0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x162FDCu;
            // 0x162fe0: 0x220102d  daddu       $v0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x162FF4u;
            goto label_162ff4;
        }
    }
    ctx->pc = 0x162FE4u;
    // 0x162fe4: 0x40f809  jalr        $v0
    ctx->pc = 0x162FE4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x162FECu);
        if (jumpTarget == 0u) {
            ctx->pc = 0x162FECu;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x162FBCu: goto label_162fbc;
            case 0x162FD0u: goto label_162fd0;
            case 0x162FECu: goto label_162fec;
            case 0x162FF0u: goto label_162ff0;
            case 0x162FF4u: goto label_162ff4;
            case 0x16302Cu: goto label_16302c;
            case 0x163040u: goto label_163040;
            case 0x16305Cu: goto label_16305c;
            case 0x163060u: goto label_163060;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x162FECu; }
            if (ctx->pc != 0x162FECu) { return; }
        }
        }
    }
    ctx->pc = 0x162FECu;
label_162fec:
    // 0x162fec: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x162fecu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
label_162ff0:
    // 0x162ff0: 0x220102d  daddu       $v0, $s1, $zero
    ctx->pc = 0x162ff0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
label_162ff4:
    // 0x162ff4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x162ff4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x162ff8: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x162ff8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x162ffc: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x162ffcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x163000: 0x3e00008  jr          $ra
    ctx->pc = 0x163000u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x163004u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x163000u;
            // 0x163004: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x162FBCu: goto label_162fbc;
            case 0x162FD0u: goto label_162fd0;
            case 0x162FECu: goto label_162fec;
            case 0x162FF0u: goto label_162ff0;
            case 0x162FF4u: goto label_162ff4;
            case 0x16302Cu: goto label_16302c;
            case 0x163040u: goto label_163040;
            case 0x16305Cu: goto label_16305c;
            case 0x163060u: goto label_163060;
            default: break;
        }
        return;
    }
    ctx->pc = 0x163008u;
    // 0x163008: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x163008u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x16300c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x16300cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x163010: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x163010u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x163014: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x163014u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x163018: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x163018u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16301c: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x16301cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x163020: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x163020u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x163024: 0xc058d10  jal         func_163440
    ctx->pc = 0x163024u;
    SET_GPR_U32(ctx, 31, 0x16302Cu);
    ctx->pc = 0x163028u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x163024u;
            // 0x163028: 0xc0902d  daddu       $s2, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163440u;
    if (runtime->hasFunction(0x163440u)) {
        auto targetFn = runtime->lookupFunction(0x163440u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16302Cu; }
        if (ctx->pc != 0x16302Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163440_0x163440(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16302Cu; }
        if (ctx->pc != 0x16302Cu) { return; }
    }
    ctx->pc = 0x16302Cu;
label_16302c:
    // 0x16302c: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x16302cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x163030: 0x5443000b  bnel        $v0, $v1, . + 4 + (0xB << 2)
    ctx->pc = 0x163030u;
    {
        const bool branch_taken_0x163030 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        if (branch_taken_0x163030) {
            ctx->pc = 0x163034u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x163030u;
            // 0x163034: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x163060u;
            goto label_163060;
        }
    }
    ctx->pc = 0x163038u;
    // 0x163038: 0xc058d08  jal         func_163420
    ctx->pc = 0x163038u;
    SET_GPR_U32(ctx, 31, 0x163040u);
    ctx->pc = 0x163420u;
    if (runtime->hasFunction(0x163420u)) {
        auto targetFn = runtime->lookupFunction(0x163420u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x163040u; }
        if (ctx->pc != 0x163040u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163420_0x163420(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x163040u; }
        if (ctx->pc != 0x163040u) { return; }
    }
    ctx->pc = 0x163040u;
label_163040:
    // 0x163040: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x163040u;
    {
        const bool branch_taken_0x163040 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x163044u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x163040u;
            // 0x163044: 0x8e040014  lw          $a0, 0x14($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x163040) {
            ctx->pc = 0x16305Cu;
            goto label_16305c;
        }
    }
    ctx->pc = 0x163048u;
    // 0x163048: 0x8c420020  lw          $v0, 0x20($v0)
    ctx->pc = 0x163048u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 32)));
    // 0x16304c: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x16304Cu;
    {
        const bool branch_taken_0x16304c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x163050u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16304Cu;
            // 0x163050: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16304c) {
            ctx->pc = 0x16305Cu;
            goto label_16305c;
        }
    }
    ctx->pc = 0x163054u;
    // 0x163054: 0x40f809  jalr        $v0
    ctx->pc = 0x163054u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x16305Cu);
        ctx->pc = 0x163058u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x163054u;
            // 0x163058: 0x240302d  daddu       $a2, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x16305Cu;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x162FBCu: goto label_162fbc;
            case 0x162FD0u: goto label_162fd0;
            case 0x162FECu: goto label_162fec;
            case 0x162FF0u: goto label_162ff0;
            case 0x162FF4u: goto label_162ff4;
            case 0x16302Cu: goto label_16302c;
            case 0x163040u: goto label_163040;
            case 0x16305Cu: goto label_16305c;
            case 0x163060u: goto label_163060;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x16305Cu; }
            if (ctx->pc != 0x16305Cu) { return; }
        }
        }
    }
    ctx->pc = 0x16305Cu;
label_16305c:
    // 0x16305c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x16305cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_163060:
    // 0x163060: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x163060u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x163064: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x163064u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x163068: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x163068u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x16306c: 0x3e00008  jr          $ra
    ctx->pc = 0x16306Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x163070u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16306Cu;
            // 0x163070: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x162FBCu: goto label_162fbc;
            case 0x162FD0u: goto label_162fd0;
            case 0x162FECu: goto label_162fec;
            case 0x162FF0u: goto label_162ff0;
            case 0x162FF4u: goto label_162ff4;
            case 0x16302Cu: goto label_16302c;
            case 0x163040u: goto label_163040;
            case 0x16305Cu: goto label_16305c;
            case 0x163060u: goto label_163060;
            default: break;
        }
        return;
    }
    ctx->pc = 0x163074u;
    // 0x163074: 0x0  nop
    ctx->pc = 0x163074u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
