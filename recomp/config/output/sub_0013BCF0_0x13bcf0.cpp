#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013BCF0
// Address: 0x13bcf0 - 0x13bdb4
void sub_0013BCF0_0x13bcf0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013BCF0_0x13bcf0");
#endif

    switch (ctx->pc) {
        case 0x13bd68u: goto label_13bd68;
        case 0x13bd78u: goto label_13bd78;
        case 0x13bd88u: goto label_13bd88;
        case 0x13bd98u: goto label_13bd98;
        default: break;
    }

    ctx->pc = 0x13bcf0u;

    // 0x13bcf0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x13bcf0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x13bcf4: 0x182d  daddu       $v1, $zero, $zero
    ctx->pc = 0x13bcf4u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13bcf8: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x13bcf8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x13bcfc: 0x1080002a  beqz        $a0, . + 4 + (0x2A << 2)
    ctx->pc = 0x13BCFCu;
    {
        const bool branch_taken_0x13bcfc = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x13BD00u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13BCFCu;
            // 0x13bd00: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13bcfc) {
            ctx->pc = 0x13BDA8u;
            goto label_13bda8;
        }
    }
    ctx->pc = 0x13BD04u;
    // 0x13bd04: 0x240200cb  addiu       $v0, $zero, 0xCB
    ctx->pc = 0x13bd04u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 203));
    // 0x13bd08: 0x10a20021  beq         $a1, $v0, . + 4 + (0x21 << 2)
    ctx->pc = 0x13BD08u;
    {
        const bool branch_taken_0x13bd08 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 2));
        ctx->pc = 0x13BD0Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13BD08u;
            // 0x13bd0c: 0x28a200cc  slti        $v0, $a1, 0xCC (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)204) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x13bd08) {
            ctx->pc = 0x13BD90u;
            goto label_13bd90;
        }
    }
    ctx->pc = 0x13BD10u;
    // 0x13bd10: 0x1040000b  beqz        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x13BD10u;
    {
        const bool branch_taken_0x13bd10 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x13BD14u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13BD10u;
            // 0x13bd14: 0x240200cd  addiu       $v0, $zero, 0xCD (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 205));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13bd10) {
            ctx->pc = 0x13BD40u;
            goto label_13bd40;
        }
    }
    ctx->pc = 0x13BD18u;
    // 0x13bd18: 0x240200c9  addiu       $v0, $zero, 0xC9
    ctx->pc = 0x13bd18u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 201));
    // 0x13bd1c: 0x10a20014  beq         $a1, $v0, . + 4 + (0x14 << 2)
    ctx->pc = 0x13BD1Cu;
    {
        const bool branch_taken_0x13bd1c = (GPR_U64(ctx, 5) == GPR_U64(ctx, 2));
        ctx->pc = 0x13BD20u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13BD1Cu;
            // 0x13bd20: 0x28a200ca  slti        $v0, $a1, 0xCA (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)202) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x13bd1c) {
            ctx->pc = 0x13BD70u;
            goto label_13bd70;
        }
    }
    ctx->pc = 0x13BD24u;
    // 0x13bd24: 0x10400016  beqz        $v0, . + 4 + (0x16 << 2)
    ctx->pc = 0x13BD24u;
    {
        const bool branch_taken_0x13bd24 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x13BD28u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13BD24u;
            // 0x13bd28: 0x240200c8  addiu       $v0, $zero, 0xC8 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 200));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13bd24) {
            ctx->pc = 0x13BD80u;
            goto label_13bd80;
        }
    }
    ctx->pc = 0x13BD2Cu;
    // 0x13bd2c: 0x10a2000c  beq         $a1, $v0, . + 4 + (0xC << 2)
    ctx->pc = 0x13BD2Cu;
    {
        const bool branch_taken_0x13bd2c = (GPR_U64(ctx, 5) == GPR_U64(ctx, 2));
        ctx->pc = 0x13BD30u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13BD2Cu;
            // 0x13bd30: 0x60102d  daddu       $v0, $v1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13bd2c) {
            ctx->pc = 0x13BD60u;
            goto label_13bd60;
        }
    }
    ctx->pc = 0x13BD34u;
    // 0x13bd34: 0x1000001d  b           . + 4 + (0x1D << 2)
    ctx->pc = 0x13BD34u;
    {
        const bool branch_taken_0x13bd34 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x13BD38u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13BD34u;
            // 0x13bd38: 0xdfbf0000  ld          $ra, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13bd34) {
            ctx->pc = 0x13BDACu;
            goto label_13bdac;
        }
    }
    ctx->pc = 0x13BD3Cu;
    // 0x13bd3c: 0x0  nop
    ctx->pc = 0x13bd3cu;
    // NOP
label_13bd40:
    // 0x13bd40: 0x10a20013  beq         $a1, $v0, . + 4 + (0x13 << 2)
    ctx->pc = 0x13BD40u;
    {
        const bool branch_taken_0x13bd40 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 2));
        ctx->pc = 0x13BD44u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13BD40u;
            // 0x13bd44: 0x28a200cd  slti        $v0, $a1, 0xCD (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)205) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x13bd40) {
            ctx->pc = 0x13BD90u;
            goto label_13bd90;
        }
    }
    ctx->pc = 0x13BD48u;
    // 0x13bd48: 0x1440000d  bnez        $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x13BD48u;
    {
        const bool branch_taken_0x13bd48 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x13BD4Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13BD48u;
            // 0x13bd4c: 0x2402012b  addiu       $v0, $zero, 0x12B (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 299));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13bd48) {
            ctx->pc = 0x13BD80u;
            goto label_13bd80;
        }
    }
    ctx->pc = 0x13BD50u;
    // 0x13bd50: 0x10a20013  beq         $a1, $v0, . + 4 + (0x13 << 2)
    ctx->pc = 0x13BD50u;
    {
        const bool branch_taken_0x13bd50 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 2));
        ctx->pc = 0x13BD54u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13BD50u;
            // 0x13bd54: 0x60102d  daddu       $v0, $v1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13bd50) {
            ctx->pc = 0x13BDA0u;
            goto label_13bda0;
        }
    }
    ctx->pc = 0x13BD58u;
    // 0x13bd58: 0x10000014  b           . + 4 + (0x14 << 2)
    ctx->pc = 0x13BD58u;
    {
        const bool branch_taken_0x13bd58 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x13BD5Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13BD58u;
            // 0x13bd5c: 0xdfbf0000  ld          $ra, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13bd58) {
            ctx->pc = 0x13BDACu;
            goto label_13bdac;
        }
    }
    ctx->pc = 0x13BD60u;
label_13bd60:
    // 0x13bd60: 0xc04ef14  jal         func_13BC50
    ctx->pc = 0x13BD60u;
    SET_GPR_U32(ctx, 31, 0x13BD68u);
    ctx->pc = 0x13BC50u;
    if (runtime->hasFunction(0x13BC50u)) {
        auto targetFn = runtime->lookupFunction(0x13BC50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13BD68u; }
        if (ctx->pc != 0x13BD68u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013BC50_0x13bc50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13BD68u; }
        if (ctx->pc != 0x13BD68u) { return; }
    }
    ctx->pc = 0x13BD68u;
label_13bd68:
    // 0x13bd68: 0x1000000e  b           . + 4 + (0xE << 2)
    ctx->pc = 0x13BD68u;
    {
        const bool branch_taken_0x13bd68 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x13BD6Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13BD68u;
            // 0x13bd6c: 0x40182d  daddu       $v1, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13bd68) {
            ctx->pc = 0x13BDA4u;
            goto label_13bda4;
        }
    }
    ctx->pc = 0x13BD70u;
label_13bd70:
    // 0x13bd70: 0xc04ef1c  jal         func_13BC70
    ctx->pc = 0x13BD70u;
    SET_GPR_U32(ctx, 31, 0x13BD78u);
    ctx->pc = 0x13BC70u;
    if (runtime->hasFunction(0x13BC70u)) {
        auto targetFn = runtime->lookupFunction(0x13BC70u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13BD78u; }
        if (ctx->pc != 0x13BD78u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013BC70_0x13bc70(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13BD78u; }
        if (ctx->pc != 0x13BD78u) { return; }
    }
    ctx->pc = 0x13BD78u;
label_13bd78:
    // 0x13bd78: 0x1000000a  b           . + 4 + (0xA << 2)
    ctx->pc = 0x13BD78u;
    {
        const bool branch_taken_0x13bd78 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x13BD7Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13BD78u;
            // 0x13bd7c: 0x40182d  daddu       $v1, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13bd78) {
            ctx->pc = 0x13BDA4u;
            goto label_13bda4;
        }
    }
    ctx->pc = 0x13BD80u;
label_13bd80:
    // 0x13bd80: 0xc04ef28  jal         func_13BCA0
    ctx->pc = 0x13BD80u;
    SET_GPR_U32(ctx, 31, 0x13BD88u);
    ctx->pc = 0x13BCA0u;
    if (runtime->hasFunction(0x13BCA0u)) {
        auto targetFn = runtime->lookupFunction(0x13BCA0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13BD88u; }
        if (ctx->pc != 0x13BD88u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013BCA0_0x13bca0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13BD88u; }
        if (ctx->pc != 0x13BD88u) { return; }
    }
    ctx->pc = 0x13BD88u;
label_13bd88:
    // 0x13bd88: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x13BD88u;
    {
        const bool branch_taken_0x13bd88 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x13BD8Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13BD88u;
            // 0x13bd8c: 0x40182d  daddu       $v1, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13bd88) {
            ctx->pc = 0x13BDA4u;
            goto label_13bda4;
        }
    }
    ctx->pc = 0x13BD90u;
label_13bd90:
    // 0x13bd90: 0xc04ef30  jal         func_13BCC0
    ctx->pc = 0x13BD90u;
    SET_GPR_U32(ctx, 31, 0x13BD98u);
    ctx->pc = 0x13BCC0u;
    if (runtime->hasFunction(0x13BCC0u)) {
        auto targetFn = runtime->lookupFunction(0x13BCC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13BD98u; }
        if (ctx->pc != 0x13BD98u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013BCC0_0x13bcc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13BD98u; }
        if (ctx->pc != 0x13BD98u) { return; }
    }
    ctx->pc = 0x13BD98u;
label_13bd98:
    // 0x13bd98: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x13BD98u;
    {
        const bool branch_taken_0x13bd98 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x13BD9Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13BD98u;
            // 0x13bd9c: 0x40182d  daddu       $v1, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13bd98) {
            ctx->pc = 0x13BDA4u;
            goto label_13bda4;
        }
    }
    ctx->pc = 0x13BDA0u;
label_13bda0:
    // 0x13bda0: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x13bda0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_13bda4:
    // 0x13bda4: 0x60102d  daddu       $v0, $v1, $zero
    ctx->pc = 0x13bda4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
label_13bda8:
    // 0x13bda8: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x13bda8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_13bdac:
    // 0x13bdac: 0x3e00008  jr          $ra
    ctx->pc = 0x13BDACu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13BDB0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13BDACu;
            // 0x13bdb0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13BD40u: goto label_13bd40;
            case 0x13BD60u: goto label_13bd60;
            case 0x13BD68u: goto label_13bd68;
            case 0x13BD70u: goto label_13bd70;
            case 0x13BD78u: goto label_13bd78;
            case 0x13BD80u: goto label_13bd80;
            case 0x13BD88u: goto label_13bd88;
            case 0x13BD90u: goto label_13bd90;
            case 0x13BD98u: goto label_13bd98;
            case 0x13BDA0u: goto label_13bda0;
            case 0x13BDA4u: goto label_13bda4;
            case 0x13BDA8u: goto label_13bda8;
            case 0x13BDACu: goto label_13bdac;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13BDB4u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
