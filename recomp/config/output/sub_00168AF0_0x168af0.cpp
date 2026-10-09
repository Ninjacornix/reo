#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00168AF0
// Address: 0x168af0 - 0x168ba4
void sub_00168AF0_0x168af0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00168AF0_0x168af0");
#endif

    switch (ctx->pc) {
        case 0x168b0cu: goto label_168b0c;
        default: break;
    }

    ctx->pc = 0x168af0u;

    // 0x168af0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x168af0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x168af4: 0x80102d  daddu       $v0, $a0, $zero
    ctx->pc = 0x168af4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x168af8: 0xa0302d  daddu       $a2, $a1, $zero
    ctx->pc = 0x168af8u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x168afc: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x168afcu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x168b00: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x168b00u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x168b04: 0xc05a31c  jal         func_168C70
    ctx->pc = 0x168B04u;
    SET_GPR_U32(ctx, 31, 0x168B0Cu);
    ctx->pc = 0x168B08u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x168B04u;
            // 0x168b08: 0x3a0202d  daddu       $a0, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x168C70u;
    if (runtime->hasFunction(0x168C70u)) {
        auto targetFn = runtime->lookupFunction(0x168C70u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x168B0Cu; }
        if (ctx->pc != 0x168B0Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00168C70_0x168c70(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x168B0Cu; }
        if (ctx->pc != 0x168B0Cu) { return; }
    }
    ctx->pc = 0x168B0Cu;
label_168b0c:
    // 0x168b0c: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x168B0Cu;
    {
        const bool branch_taken_0x168b0c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x168B10u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x168B0Cu;
            // 0x168b10: 0x2406ffff  addiu       $a2, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x168b0c) {
            ctx->pc = 0x168B20u;
            goto label_168b20;
        }
    }
    ctx->pc = 0x168B14u;
    // 0x168b14: 0x10000020  b           . + 4 + (0x20 << 2)
    ctx->pc = 0x168B14u;
    {
        const bool branch_taken_0x168b14 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x168B18u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x168B14u;
            // 0x168b18: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x168b14) {
            ctx->pc = 0x168B98u;
            goto label_168b98;
        }
    }
    ctx->pc = 0x168B1Cu;
    // 0x168b1c: 0x0  nop
    ctx->pc = 0x168b1cu;
    // NOP
label_168b20:
    // 0x168b20: 0x93a30000  lbu         $v1, 0x0($sp)
    ctx->pc = 0x168b20u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x168b24: 0x93a40002  lbu         $a0, 0x2($sp)
    ctx->pc = 0x168b24u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 2)));
    // 0x168b28: 0x32880  sll         $a1, $v1, 2
    ctx->pc = 0x168b28u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x168b2c: 0x31900  sll         $v1, $v1, 4
    ctx->pc = 0x168b2cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 4));
    // 0x168b30: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x168b30u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x168b34: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x168b34u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x168b38: 0x3c010024  lui         $at, 0x24
    ctx->pc = 0x168b38u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)36 << 16));
    // 0x168b3c: 0x230821  addu        $at, $at, $v1
    ctx->pc = 0x168b3cu;
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 3)));
    // 0x168b40: 0x8c230680  lw          $v1, 0x680($at)
    ctx->pc = 0x168b40u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 1664)));
    // 0x168b44: 0x10660014  beq         $v1, $a2, . + 4 + (0x14 << 2)
    ctx->pc = 0x168B44u;
    {
        const bool branch_taken_0x168b44 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 6));
        ctx->pc = 0x168B48u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x168B44u;
            // 0x168b48: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x168b44) {
            ctx->pc = 0x168B98u;
            goto label_168b98;
        }
    }
    ctx->pc = 0x168B4Cu;
    // 0x168b4c: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x168b4cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x168b50: 0x852021  addu        $a0, $a0, $a1
    ctx->pc = 0x168b50u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 5)));
    // 0x168b54: 0x8c840780  lw          $a0, 0x780($a0)
    ctx->pc = 0x168b54u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 1920)));
    // 0x168b58: 0x93a20003  lbu         $v0, 0x3($sp)
    ctx->pc = 0x168b58u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 3)));
    // 0x168b5c: 0x832018  mult        $a0, $a0, $v1
    ctx->pc = 0x168b5cu;
    { int64_t result = (int64_t)GPR_S32(ctx, 4) * (int64_t)GPR_S32(ctx, 3); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 4, (int32_t)result); }
    // 0x168b60: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x168b60u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x168b64: 0x3c030024  lui         $v1, 0x24
    ctx->pc = 0x168b64u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)36 << 16));
    // 0x168b68: 0x621821  addu        $v1, $v1, $v0
    ctx->pc = 0x168b68u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x168b6c: 0x8c630670  lw          $v1, 0x670($v1)
    ctx->pc = 0x168b6cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 1648)));
    // 0x168b70: 0x41140  sll         $v0, $a0, 5
    ctx->pc = 0x168b70u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 4), 5));
    // 0x168b74: 0x318c0  sll         $v1, $v1, 3
    ctx->pc = 0x168b74u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x168b78: 0x441023  subu        $v0, $v0, $a0
    ctx->pc = 0x168b78u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x168b7c: 0x50600001  beql        $v1, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x168B7Cu;
    {
        const bool branch_taken_0x168b7c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x168b7c) {
            ctx->pc = 0x168B80u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x168B7Cu;
            // 0x168b80: 0x1cd  break       0, 7 (Delay Slot)
        runtime->handleBreak(rdram, ctx);
        ctx->in_delay_slot = false;
            ctx->pc = 0x168B84u;
            goto label_168b84;
        }
    }
    ctx->pc = 0x168B84u;
label_168b84:
    // 0x168b84: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x168b84u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x168b88: 0x441021  addu        $v0, $v0, $a0
    ctx->pc = 0x168b88u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x168b8c: 0x210c0  sll         $v0, $v0, 3
    ctx->pc = 0x168b8cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 3));
    // 0x168b90: 0x43001a  div         $zero, $v0, $v1
    ctx->pc = 0x168b90u;
    { int32_t divisor = GPR_S32(ctx, 3);    int32_t dividend = GPR_S32(ctx, 2);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x168b94: 0x1012  mflo        $v0
    ctx->pc = 0x168b94u;
    SET_GPR_U64(ctx, 2, ctx->lo);
label_168b98:
    // 0x168b98: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x168b98u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x168b9c: 0x3e00008  jr          $ra
    ctx->pc = 0x168B9Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x168BA0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x168B9Cu;
            // 0x168ba0: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x168B0Cu: goto label_168b0c;
            case 0x168B20u: goto label_168b20;
            case 0x168B84u: goto label_168b84;
            case 0x168B98u: goto label_168b98;
            default: break;
        }
        return;
    }
    ctx->pc = 0x168BA4u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
