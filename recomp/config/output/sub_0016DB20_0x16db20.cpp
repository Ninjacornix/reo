#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0016DB20
// Address: 0x16db20 - 0x16dbf8
void sub_0016DB20_0x16db20(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0016DB20_0x16db20");
#endif

    switch (ctx->pc) {
        case 0x16db54u: goto label_16db54;
        case 0x16db84u: goto label_16db84;
        case 0x16db9cu: goto label_16db9c;
        default: break;
    }

    ctx->pc = 0x16db20u;

    // 0x16db20: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x16db20u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x16db24: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x16db24u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x16db28: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x16db28u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16db2c: 0x24050034  addiu       $a1, $zero, 0x34
    ctx->pc = 0x16db2cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 52));
    // 0x16db30: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x16db30u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x16db34: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x16db34u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x16db38: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x16db38u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16db3c: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x16db3cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x16db40: 0xc0982d  daddu       $s3, $a2, $zero
    ctx->pc = 0x16db40u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16db44: 0xffb40020  sd          $s4, 0x20($sp)
    ctx->pc = 0x16db44u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 20));
    // 0x16db48: 0xffbf0028  sd          $ra, 0x28($sp)
    ctx->pc = 0x16db48u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
    // 0x16db4c: 0xc05d58a  jal         func_175628
    ctx->pc = 0x16DB4Cu;
    SET_GPR_U32(ctx, 31, 0x16DB54u);
    ctx->pc = 0x16DB50u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16DB4Cu;
            // 0x16db50: 0xe0a02d  daddu       $s4, $a3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175628u;
    if (runtime->hasFunction(0x175628u)) {
        auto targetFn = runtime->lookupFunction(0x175628u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16DB54u; }
        if (ctx->pc != 0x16DB54u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00175628_0x175628(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16DB54u; }
        if (ctx->pc != 0x16DB54u) { return; }
    }
    ctx->pc = 0x16DB54u;
label_16db54:
    // 0x16db54: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x16db54u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16db58: 0x16000011  bnez        $s0, . + 4 + (0x11 << 2)
    ctx->pc = 0x16DB58u;
    {
        const bool branch_taken_0x16db58 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        ctx->pc = 0x16DB5Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16DB58u;
            // 0x16db5c: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16db58) {
            ctx->pc = 0x16DBA0u;
            goto label_16dba0;
        }
    }
    ctx->pc = 0x16DB60u;
    // 0x16db60: 0x661000a  bgez        $s3, . + 4 + (0xA << 2)
    ctx->pc = 0x16DB60u;
    {
        const bool branch_taken_0x16db60 = (GPR_S64(ctx, 19) >= 0);
        ctx->pc = 0x16DB64u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16DB60u;
            // 0x16db64: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16db60) {
            ctx->pc = 0x16DB8Cu;
            goto label_16db8c;
        }
    }
    ctx->pc = 0x16DB68u;
    // 0x16db68: 0x8e420030  lw          $v0, 0x30($s2)
    ctx->pc = 0x16db68u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 48)));
    // 0x16db6c: 0x10400008  beqz        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x16DB6Cu;
    {
        const bool branch_taken_0x16db6c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x16DB70u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16DB6Cu;
            // 0x16db70: 0x24050034  addiu       $a1, $zero, 0x34 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 52));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16db6c) {
            ctx->pc = 0x16DB90u;
            goto label_16db90;
        }
    }
    ctx->pc = 0x16DB74u;
    // 0x16db74: 0x5280000a  beql        $s4, $zero, . + 4 + (0xA << 2)
    ctx->pc = 0x16DB74u;
    {
        const bool branch_taken_0x16db74 = (GPR_U64(ctx, 20) == GPR_U64(ctx, 0));
        if (branch_taken_0x16db74) {
            ctx->pc = 0x16DB78u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x16DB74u;
            // 0x16db78: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
            ctx->pc = 0x16DBA0u;
            goto label_16dba0;
        }
    }
    ctx->pc = 0x16DB7Cu;
    // 0x16db7c: 0xc05b6fe  jal         func_16DBF8
    ctx->pc = 0x16DB7Cu;
    SET_GPR_U32(ctx, 31, 0x16DB84u);
    ctx->pc = 0x16DB80u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16DB7Cu;
            // 0x16db80: 0x240282d  daddu       $a1, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x16DBF8u;
    if (runtime->hasFunction(0x16DBF8u)) {
        auto targetFn = runtime->lookupFunction(0x16DBF8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16DB84u; }
        if (ctx->pc != 0x16DB84u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0016DBF8_0x16dbf8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16DB84u; }
        if (ctx->pc != 0x16DB84u) { return; }
    }
    ctx->pc = 0x16DB84u;
label_16db84:
    // 0x16db84: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x16DB84u;
    {
        const bool branch_taken_0x16db84 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x16DB88u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16DB84u;
            // 0x16db88: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16db84) {
            ctx->pc = 0x16DB9Cu;
            goto label_16db9c;
        }
    }
    ctx->pc = 0x16DB8Cu;
label_16db8c:
    // 0x16db8c: 0x24050034  addiu       $a1, $zero, 0x34
    ctx->pc = 0x16db8cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 52));
label_16db90:
    // 0x16db90: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x16db90u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x16db94: 0xc05d518  jal         func_175460
    ctx->pc = 0x16DB94u;
    SET_GPR_U32(ctx, 31, 0x16DB9Cu);
    ctx->pc = 0x16DB98u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16DB94u;
            // 0x16db98: 0x24100001  addiu       $s0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175460u;
    if (runtime->hasFunction(0x175460u)) {
        auto targetFn = runtime->lookupFunction(0x175460u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16DB9Cu; }
        if (ctx->pc != 0x16DB9Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00175460_0x175460(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16DB9Cu; }
        if (ctx->pc != 0x16DB9Cu) { return; }
    }
    ctx->pc = 0x16DB9Cu;
label_16db9c:
    // 0x16db9c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x16db9cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_16dba0:
    // 0x16dba0: 0x1602000d  bne         $s0, $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x16DBA0u;
    {
        const bool branch_taken_0x16dba0 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 2));
        ctx->pc = 0x16DBA4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16DBA0u;
            // 0x16dba4: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16dba0) {
            ctx->pc = 0x16DBD8u;
            goto label_16dbd8;
        }
    }
    ctx->pc = 0x16DBA8u;
    // 0x16dba8: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x16dba8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16dbac: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x16dbacu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x16dbb0: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x16dbb0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16dbb4: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x16dbb4u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x16dbb8: 0x260302d  daddu       $a2, $s3, $zero
    ctx->pc = 0x16dbb8u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16dbbc: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x16dbbcu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x16dbc0: 0x280382d  daddu       $a3, $s4, $zero
    ctx->pc = 0x16dbc0u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16dbc4: 0xdfb40020  ld          $s4, 0x20($sp)
    ctx->pc = 0x16dbc4u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x16dbc8: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x16dbc8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x16dbcc: 0x805b722  j           func_16DC88
    ctx->pc = 0x16DBCCu;
    ctx->pc = 0x16DBD0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16DBCCu;
            // 0x16dbd0: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
    ctx->pc = 0x16DC88u;
    if (runtime->hasFunction(0x16DC88u)) {
        auto targetFn = runtime->lookupFunction(0x16DC88u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0016DC88_0x16dc88(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x16DBD4u;
    // 0x16dbd4: 0x0  nop
    ctx->pc = 0x16dbd4u;
    // NOP
label_16dbd8:
    // 0x16dbd8: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x16dbd8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x16dbdc: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x16dbdcu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x16dbe0: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x16dbe0u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x16dbe4: 0xdfb40020  ld          $s4, 0x20($sp)
    ctx->pc = 0x16dbe4u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x16dbe8: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x16dbe8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x16dbec: 0x3e00008  jr          $ra
    ctx->pc = 0x16DBECu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x16DBF0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16DBECu;
            // 0x16dbf0: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x16DB54u: goto label_16db54;
            case 0x16DB84u: goto label_16db84;
            case 0x16DB8Cu: goto label_16db8c;
            case 0x16DB90u: goto label_16db90;
            case 0x16DB9Cu: goto label_16db9c;
            case 0x16DBA0u: goto label_16dba0;
            case 0x16DBD8u: goto label_16dbd8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x16DBF4u;
    // 0x16dbf4: 0x0  nop
    ctx->pc = 0x16dbf4u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
