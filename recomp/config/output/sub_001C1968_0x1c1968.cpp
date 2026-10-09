#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C1968
// Address: 0x1c1968 - 0x1c19d0
void sub_001C1968_0x1c1968(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C1968_0x1c1968");
#endif

    switch (ctx->pc) {
        case 0x1c1980u: goto label_1c1980;
        case 0x1c198cu: goto label_1c198c;
        case 0x1c1998u: goto label_1c1998;
        case 0x1c19a4u: goto label_1c19a4;
        case 0x1c19b0u: goto label_1c19b0;
        case 0x1c19bcu: goto label_1c19bc;
        default: break;
    }

    ctx->pc = 0x1c1968u;

    // 0x1c1968: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1c1968u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1c196c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1c196cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1c1970: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1c1970u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1c1974: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1c1974u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c1978: 0xc07062c  jal         func_1C18B0
    ctx->pc = 0x1C1978u;
    SET_GPR_U32(ctx, 31, 0x1C1980u);
    ctx->pc = 0x1C197Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1978u;
            // 0x1c197c: 0x92040007  lbu         $a0, 0x7($s0) (Delay Slot)
        SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 7)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C18B0u;
    if (runtime->hasFunction(0x1C18B0u)) {
        auto targetFn = runtime->lookupFunction(0x1C18B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C1980u; }
        if (ctx->pc != 0x1C1980u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C18B0_0x1c18b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C1980u; }
        if (ctx->pc != 0x1C1980u) { return; }
    }
    ctx->pc = 0x1C1980u;
label_1c1980:
    // 0x1c1980: 0x92040006  lbu         $a0, 0x6($s0)
    ctx->pc = 0x1c1980u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 6)));
    // 0x1c1984: 0xc07062c  jal         func_1C18B0
    ctx->pc = 0x1C1984u;
    SET_GPR_U32(ctx, 31, 0x1C198Cu);
    ctx->pc = 0x1C1988u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1984u;
            // 0x1c1988: 0xa2020007  sb          $v0, 0x7($s0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 16), 7), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C18B0u;
    if (runtime->hasFunction(0x1C18B0u)) {
        auto targetFn = runtime->lookupFunction(0x1C18B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C198Cu; }
        if (ctx->pc != 0x1C198Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C18B0_0x1c18b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C198Cu; }
        if (ctx->pc != 0x1C198Cu) { return; }
    }
    ctx->pc = 0x1C198Cu;
label_1c198c:
    // 0x1c198c: 0x92040005  lbu         $a0, 0x5($s0)
    ctx->pc = 0x1c198cu;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 5)));
    // 0x1c1990: 0xc07062c  jal         func_1C18B0
    ctx->pc = 0x1C1990u;
    SET_GPR_U32(ctx, 31, 0x1C1998u);
    ctx->pc = 0x1C1994u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1990u;
            // 0x1c1994: 0xa2020006  sb          $v0, 0x6($s0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 16), 6), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C18B0u;
    if (runtime->hasFunction(0x1C18B0u)) {
        auto targetFn = runtime->lookupFunction(0x1C18B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C1998u; }
        if (ctx->pc != 0x1C1998u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C18B0_0x1c18b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C1998u; }
        if (ctx->pc != 0x1C1998u) { return; }
    }
    ctx->pc = 0x1C1998u;
label_1c1998:
    // 0x1c1998: 0x92040003  lbu         $a0, 0x3($s0)
    ctx->pc = 0x1c1998u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 3)));
    // 0x1c199c: 0xc07062c  jal         func_1C18B0
    ctx->pc = 0x1C199Cu;
    SET_GPR_U32(ctx, 31, 0x1C19A4u);
    ctx->pc = 0x1C19A0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C199Cu;
            // 0x1c19a0: 0xa2020005  sb          $v0, 0x5($s0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 16), 5), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C18B0u;
    if (runtime->hasFunction(0x1C18B0u)) {
        auto targetFn = runtime->lookupFunction(0x1C18B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C19A4u; }
        if (ctx->pc != 0x1C19A4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C18B0_0x1c18b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C19A4u; }
        if (ctx->pc != 0x1C19A4u) { return; }
    }
    ctx->pc = 0x1C19A4u;
label_1c19a4:
    // 0x1c19a4: 0x92040002  lbu         $a0, 0x2($s0)
    ctx->pc = 0x1c19a4u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 2)));
    // 0x1c19a8: 0xc07062c  jal         func_1C18B0
    ctx->pc = 0x1C19A8u;
    SET_GPR_U32(ctx, 31, 0x1C19B0u);
    ctx->pc = 0x1C19ACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C19A8u;
            // 0x1c19ac: 0xa2020003  sb          $v0, 0x3($s0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 16), 3), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C18B0u;
    if (runtime->hasFunction(0x1C18B0u)) {
        auto targetFn = runtime->lookupFunction(0x1C18B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C19B0u; }
        if (ctx->pc != 0x1C19B0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C18B0_0x1c18b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C19B0u; }
        if (ctx->pc != 0x1C19B0u) { return; }
    }
    ctx->pc = 0x1C19B0u;
label_1c19b0:
    // 0x1c19b0: 0x92040001  lbu         $a0, 0x1($s0)
    ctx->pc = 0x1c19b0u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 1)));
    // 0x1c19b4: 0xc07062c  jal         func_1C18B0
    ctx->pc = 0x1C19B4u;
    SET_GPR_U32(ctx, 31, 0x1C19BCu);
    ctx->pc = 0x1C19B8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C19B4u;
            // 0x1c19b8: 0xa2020002  sb          $v0, 0x2($s0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 16), 2), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C18B0u;
    if (runtime->hasFunction(0x1C18B0u)) {
        auto targetFn = runtime->lookupFunction(0x1C18B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C19BCu; }
        if (ctx->pc != 0x1C19BCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C18B0_0x1c18b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C19BCu; }
        if (ctx->pc != 0x1C19BCu) { return; }
    }
    ctx->pc = 0x1C19BCu;
label_1c19bc:
    // 0x1c19bc: 0xa2020001  sb          $v0, 0x1($s0)
    ctx->pc = 0x1c19bcu;
    WRITE8(ADD32(GPR_U32(ctx, 16), 1), (uint8_t)GPR_U32(ctx, 2));
    // 0x1c19c0: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1c19c0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1c19c4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1c19c4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1c19c8: 0x3e00008  jr          $ra
    ctx->pc = 0x1C19C8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C19CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C19C8u;
            // 0x1c19cc: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C1980u: goto label_1c1980;
            case 0x1C198Cu: goto label_1c198c;
            case 0x1C1998u: goto label_1c1998;
            case 0x1C19A4u: goto label_1c19a4;
            case 0x1C19B0u: goto label_1c19b0;
            case 0x1C19BCu: goto label_1c19bc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C19D0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
