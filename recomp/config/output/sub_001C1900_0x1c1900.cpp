#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C1900
// Address: 0x1c1900 - 0x1c1b30
void sub_001C1900_0x1c1900(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C1900_0x1c1900");
#endif

    switch (ctx->pc) {
        case 0x1c1918u: goto label_1c1918;
        case 0x1c1924u: goto label_1c1924;
        case 0x1c1930u: goto label_1c1930;
        case 0x1c193cu: goto label_1c193c;
        case 0x1c1948u: goto label_1c1948;
        case 0x1c1954u: goto label_1c1954;
        case 0x1c1980u: goto label_1c1980;
        case 0x1c198cu: goto label_1c198c;
        case 0x1c1998u: goto label_1c1998;
        case 0x1c19a4u: goto label_1c19a4;
        case 0x1c19b0u: goto label_1c19b0;
        case 0x1c19bcu: goto label_1c19bc;
        default: break;
    }

    ctx->pc = 0x1c1900u;

    // 0x1c1900: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1c1900u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1c1904: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1c1904u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1c1908: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1c1908u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1c190c: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1c190cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c1910: 0xc070638  jal         func_1C18E0
    ctx->pc = 0x1C1910u;
    SET_GPR_U32(ctx, 31, 0x1C1918u);
    ctx->pc = 0x1C1914u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1910u;
            // 0x1c1914: 0x92040007  lbu         $a0, 0x7($s0) (Delay Slot)
        SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 7)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C18E0u;
    if (runtime->hasFunction(0x1C18E0u)) {
        auto targetFn = runtime->lookupFunction(0x1C18E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C1918u; }
        if (ctx->pc != 0x1C1918u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C18E0_0x1c18e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C1918u; }
        if (ctx->pc != 0x1C1918u) { return; }
    }
    ctx->pc = 0x1C1918u;
label_1c1918:
    // 0x1c1918: 0x92040006  lbu         $a0, 0x6($s0)
    ctx->pc = 0x1c1918u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 6)));
    // 0x1c191c: 0xc070638  jal         func_1C18E0
    ctx->pc = 0x1C191Cu;
    SET_GPR_U32(ctx, 31, 0x1C1924u);
    ctx->pc = 0x1C1920u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C191Cu;
            // 0x1c1920: 0xa2020007  sb          $v0, 0x7($s0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 16), 7), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C18E0u;
    if (runtime->hasFunction(0x1C18E0u)) {
        auto targetFn = runtime->lookupFunction(0x1C18E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C1924u; }
        if (ctx->pc != 0x1C1924u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C18E0_0x1c18e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C1924u; }
        if (ctx->pc != 0x1C1924u) { return; }
    }
    ctx->pc = 0x1C1924u;
label_1c1924:
    // 0x1c1924: 0x92040005  lbu         $a0, 0x5($s0)
    ctx->pc = 0x1c1924u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 5)));
    // 0x1c1928: 0xc070638  jal         func_1C18E0
    ctx->pc = 0x1C1928u;
    SET_GPR_U32(ctx, 31, 0x1C1930u);
    ctx->pc = 0x1C192Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1928u;
            // 0x1c192c: 0xa2020006  sb          $v0, 0x6($s0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 16), 6), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C18E0u;
    if (runtime->hasFunction(0x1C18E0u)) {
        auto targetFn = runtime->lookupFunction(0x1C18E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C1930u; }
        if (ctx->pc != 0x1C1930u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C18E0_0x1c18e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C1930u; }
        if (ctx->pc != 0x1C1930u) { return; }
    }
    ctx->pc = 0x1C1930u;
label_1c1930:
    // 0x1c1930: 0x92040003  lbu         $a0, 0x3($s0)
    ctx->pc = 0x1c1930u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 3)));
    // 0x1c1934: 0xc070638  jal         func_1C18E0
    ctx->pc = 0x1C1934u;
    SET_GPR_U32(ctx, 31, 0x1C193Cu);
    ctx->pc = 0x1C1938u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1934u;
            // 0x1c1938: 0xa2020005  sb          $v0, 0x5($s0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 16), 5), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C18E0u;
    if (runtime->hasFunction(0x1C18E0u)) {
        auto targetFn = runtime->lookupFunction(0x1C18E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C193Cu; }
        if (ctx->pc != 0x1C193Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C18E0_0x1c18e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C193Cu; }
        if (ctx->pc != 0x1C193Cu) { return; }
    }
    ctx->pc = 0x1C193Cu;
label_1c193c:
    // 0x1c193c: 0x92040002  lbu         $a0, 0x2($s0)
    ctx->pc = 0x1c193cu;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 2)));
    // 0x1c1940: 0xc070638  jal         func_1C18E0
    ctx->pc = 0x1C1940u;
    SET_GPR_U32(ctx, 31, 0x1C1948u);
    ctx->pc = 0x1C1944u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1940u;
            // 0x1c1944: 0xa2020003  sb          $v0, 0x3($s0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 16), 3), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C18E0u;
    if (runtime->hasFunction(0x1C18E0u)) {
        auto targetFn = runtime->lookupFunction(0x1C18E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C1948u; }
        if (ctx->pc != 0x1C1948u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C18E0_0x1c18e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C1948u; }
        if (ctx->pc != 0x1C1948u) { return; }
    }
    ctx->pc = 0x1C1948u;
label_1c1948:
    // 0x1c1948: 0x92040001  lbu         $a0, 0x1($s0)
    ctx->pc = 0x1c1948u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 1)));
    // 0x1c194c: 0xc070638  jal         func_1C18E0
    ctx->pc = 0x1C194Cu;
    SET_GPR_U32(ctx, 31, 0x1C1954u);
    ctx->pc = 0x1C1950u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C194Cu;
            // 0x1c1950: 0xa2020002  sb          $v0, 0x2($s0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 16), 2), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C18E0u;
    if (runtime->hasFunction(0x1C18E0u)) {
        auto targetFn = runtime->lookupFunction(0x1C18E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C1954u; }
        if (ctx->pc != 0x1C1954u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C18E0_0x1c18e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C1954u; }
        if (ctx->pc != 0x1C1954u) { return; }
    }
    ctx->pc = 0x1C1954u;
label_1c1954:
    // 0x1c1954: 0xa2020001  sb          $v0, 0x1($s0)
    ctx->pc = 0x1c1954u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 1), (uint8_t)GPR_U32(ctx, 2));
    // 0x1c1958: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1c1958u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1c195c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1c195cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1c1960: 0x3e00008  jr          $ra
    ctx->pc = 0x1C1960u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C1964u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1960u;
            // 0x1c1964: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C1918u: goto label_1c1918;
            case 0x1C1924u: goto label_1c1924;
            case 0x1C1930u: goto label_1c1930;
            case 0x1C193Cu: goto label_1c193c;
            case 0x1C1948u: goto label_1c1948;
            case 0x1C1954u: goto label_1c1954;
            case 0x1C1980u: goto label_1c1980;
            case 0x1C198Cu: goto label_1c198c;
            case 0x1C1998u: goto label_1c1998;
            case 0x1C19A4u: goto label_1c19a4;
            case 0x1C19B0u: goto label_1c19b0;
            case 0x1C19BCu: goto label_1c19bc;
            case 0x1C1A20u: goto label_1c1a20;
            case 0x1C1A70u: goto label_1c1a70;
            case 0x1C1A74u: goto label_1c1a74;
            case 0x1C1A7Cu: goto label_1c1a7c;
            case 0x1C1AD8u: goto label_1c1ad8;
            case 0x1C1B08u: goto label_1c1b08;
            case 0x1C1B14u: goto label_1c1b14;
            case 0x1C1B24u: goto label_1c1b24;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C1968u;
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
            case 0x1C1918u: goto label_1c1918;
            case 0x1C1924u: goto label_1c1924;
            case 0x1C1930u: goto label_1c1930;
            case 0x1C193Cu: goto label_1c193c;
            case 0x1C1948u: goto label_1c1948;
            case 0x1C1954u: goto label_1c1954;
            case 0x1C1980u: goto label_1c1980;
            case 0x1C198Cu: goto label_1c198c;
            case 0x1C1998u: goto label_1c1998;
            case 0x1C19A4u: goto label_1c19a4;
            case 0x1C19B0u: goto label_1c19b0;
            case 0x1C19BCu: goto label_1c19bc;
            case 0x1C1A20u: goto label_1c1a20;
            case 0x1C1A70u: goto label_1c1a70;
            case 0x1C1A74u: goto label_1c1a74;
            case 0x1C1A7Cu: goto label_1c1a7c;
            case 0x1C1AD8u: goto label_1c1ad8;
            case 0x1C1B08u: goto label_1c1b08;
            case 0x1C1B14u: goto label_1c1b14;
            case 0x1C1B24u: goto label_1c1b24;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C19D0u;
    // 0x1c19d0: 0x80282d  daddu       $a1, $a0, $zero
    ctx->pc = 0x1c19d0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c19d4: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1c19d4u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1c19d8: 0x90a30005  lbu         $v1, 0x5($a1)
    ctx->pc = 0x1c19d8u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 5), 5)));
    // 0x1c19dc: 0x3c020025  lui         $v0, 0x25
    ctx->pc = 0x1c19dcu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)37 << 16));
    // 0x1c19e0: 0x90a40007  lbu         $a0, 0x7($a1)
    ctx->pc = 0x1c19e0u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 5), 7)));
    // 0x1c19e4: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x1c19e4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1c19e8: 0x24490688  addiu       $t1, $v0, 0x688
    ctx->pc = 0x1c19e8u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 2), 1672));
    // 0x1c19ec: 0x69260007  ldl         $a2, 0x7($t1)
    ctx->pc = 0x1c19ecu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 9), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 6, (GPR_U64(ctx, 6) & keepMask) | (mem << shift)); }
    // 0x1c19f0: 0x6d260000  ldr         $a2, 0x0($t1)
    ctx->pc = 0x1c19f0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 9), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 6, (GPR_U64(ctx, 6) & keepMask) | (mem >> shift)); }
    // 0x1c19f4: 0x8927000b  lwl         $a3, 0xB($t1)
    ctx->pc = 0x1c19f4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 9), 11); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = (3u - offset) << 3; uint32_t keepMask = (shift == 0) ? 0u : ((1u << shift) - 1u); uint32_t merged = (GPR_U32(ctx, 7) & keepMask) | (mem << shift); SET_GPR_S32(ctx, 7, (int32_t)merged); }
    // 0x1c19f8: 0x99270008  lwr         $a3, 0x8($t1)
    ctx->pc = 0x1c19f8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 9), 8); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = offset << 3; uint32_t keepMask = (offset == 0) ? 0u : (0xFFFFFFFFu << ((4u - offset) << 3)); uint32_t merged32 = (GPR_U32(ctx, 7) & keepMask) | (mem >> shift); uint64_t merged64 = (GPR_U64(ctx, 7) & 0xFFFFFFFF00000000ull) | (uint64_t)merged32; if (offset == 0) merged64 = (uint64_t)(int64_t)(int32_t)merged32; SET_GPR_U64(ctx, 7, merged64); }
    // 0x1c19fc: 0xb3a60007  sdl         $a2, 0x7($sp)
    ctx->pc = 0x1c19fcu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 6); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x1c1a00: 0xb7a60000  sdr         $a2, 0x0($sp)
    ctx->pc = 0x1c1a00u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 6); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x1c1a04: 0xaba7000b  swl         $a3, 0xB($sp)
    ctx->pc = 0x1c1a04u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 11); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = (3u - offset) << 3; uint32_t mask = 0xFFFFFFFFu >> shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 7); uint32_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x1c1a08: 0xbba70008  swr         $a3, 0x8($sp)
    ctx->pc = 0x1c1a08u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 8); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = offset << 3; uint32_t mask = 0xFFFFFFFFu << shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 7); uint32_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x1c1a0c: 0x30840003  andi        $a0, $a0, 0x3
    ctx->pc = 0x1c1a0cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)3);
    // 0x1c1a10: 0x14800003  bnez        $a0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C1A10u;
    {
        const bool branch_taken_0x1c1a10 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x1C1A14u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1A10u;
            // 0x1c1a14: 0xa0a30005  sb          $v1, 0x5($a1) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 5), 5), (uint8_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c1a10) {
            ctx->pc = 0x1C1A20u;
            goto label_1c1a20;
        }
    }
    ctx->pc = 0x1C1A18u;
    // 0x1c1a18: 0x2402001d  addiu       $v0, $zero, 0x1D
    ctx->pc = 0x1c1a18u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 29));
    // 0x1c1a1c: 0xa3a20001  sb          $v0, 0x1($sp)
    ctx->pc = 0x1c1a1cu;
    WRITE8(ADD32(GPR_U32(ctx, 29), 1), (uint8_t)GPR_U32(ctx, 2));
label_1c1a20:
    // 0x1c1a20: 0x90a20006  lbu         $v0, 0x6($a1)
    ctx->pc = 0x1c1a20u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 5), 6)));
    // 0x1c1a24: 0x90a40005  lbu         $a0, 0x5($a1)
    ctx->pc = 0x1c1a24u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 5), 5)));
    // 0x1c1a28: 0x5d1021  addu        $v0, $v0, $sp
    ctx->pc = 0x1c1a28u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 29)));
    // 0x1c1a2c: 0x8043ffff  lb          $v1, -0x1($v0)
    ctx->pc = 0x1c1a2cu;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 2), 4294967295)));
    // 0x1c1a30: 0x64182a  slt         $v1, $v1, $a0
    ctx->pc = 0x1c1a30u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 3) < (int64_t)GPR_S64(ctx, 4)) ? 1 : 0);
    // 0x1c1a34: 0x10600011  beqz        $v1, . + 4 + (0x11 << 2)
    ctx->pc = 0x1C1A34u;
    {
        const bool branch_taken_0x1c1a34 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C1A38u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1A34u;
            // 0x1c1a38: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c1a34) {
            ctx->pc = 0x1C1A7Cu;
            goto label_1c1a7c;
        }
    }
    ctx->pc = 0x1C1A3Cu;
    // 0x1c1a3c: 0x90a30006  lbu         $v1, 0x6($a1)
    ctx->pc = 0x1c1a3cu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 5), 6)));
    // 0x1c1a40: 0xa0a20005  sb          $v0, 0x5($a1)
    ctx->pc = 0x1c1a40u;
    WRITE8(ADD32(GPR_U32(ctx, 5), 5), (uint8_t)GPR_U32(ctx, 2));
    // 0x1c1a44: 0x2404000d  addiu       $a0, $zero, 0xD
    ctx->pc = 0x1c1a44u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 13));
    // 0x1c1a48: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x1c1a48u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1c1a4c: 0x306200ff  andi        $v0, $v1, 0xFF
    ctx->pc = 0x1c1a4cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)255);
    // 0x1c1a50: 0x1444000a  bne         $v0, $a0, . + 4 + (0xA << 2)
    ctx->pc = 0x1C1A50u;
    {
        const bool branch_taken_0x1c1a50 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 4));
        ctx->pc = 0x1C1A54u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1A50u;
            // 0x1c1a54: 0xa0a30006  sb          $v1, 0x6($a1) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 5), 6), (uint8_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c1a50) {
            ctx->pc = 0x1C1A7Cu;
            goto label_1c1a7c;
        }
    }
    ctx->pc = 0x1C1A58u;
    // 0x1c1a58: 0x90a30007  lbu         $v1, 0x7($a1)
    ctx->pc = 0x1c1a58u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 5), 7)));
    // 0x1c1a5c: 0x24020063  addiu       $v0, $zero, 0x63
    ctx->pc = 0x1c1a5cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 99));
    // 0x1c1a60: 0x14620003  bne         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C1A60u;
    {
        const bool branch_taken_0x1c1a60 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x1C1A64u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1A60u;
            // 0x1c1a64: 0x24620001  addiu       $v0, $v1, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c1a60) {
            ctx->pc = 0x1C1A70u;
            goto label_1c1a70;
        }
    }
    ctx->pc = 0x1C1A68u;
    // 0x1c1a68: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1C1A68u;
    {
        const bool branch_taken_0x1c1a68 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C1A6Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1A68u;
            // 0x1c1a6c: 0xa0a00007  sb          $zero, 0x7($a1) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 5), 7), (uint8_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c1a68) {
            ctx->pc = 0x1C1A74u;
            goto label_1c1a74;
        }
    }
    ctx->pc = 0x1C1A70u;
label_1c1a70:
    // 0x1c1a70: 0xa0a20007  sb          $v0, 0x7($a1)
    ctx->pc = 0x1c1a70u;
    WRITE8(ADD32(GPR_U32(ctx, 5), 7), (uint8_t)GPR_U32(ctx, 2));
label_1c1a74:
    // 0x1c1a74: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1c1a74u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1c1a78: 0xa0a20006  sb          $v0, 0x6($a1)
    ctx->pc = 0x1c1a78u;
    WRITE8(ADD32(GPR_U32(ctx, 5), 6), (uint8_t)GPR_U32(ctx, 2));
label_1c1a7c:
    // 0x1c1a7c: 0x3e00008  jr          $ra
    ctx->pc = 0x1C1A7Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C1A80u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1A7Cu;
            // 0x1c1a80: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C1918u: goto label_1c1918;
            case 0x1C1924u: goto label_1c1924;
            case 0x1C1930u: goto label_1c1930;
            case 0x1C193Cu: goto label_1c193c;
            case 0x1C1948u: goto label_1c1948;
            case 0x1C1954u: goto label_1c1954;
            case 0x1C1980u: goto label_1c1980;
            case 0x1C198Cu: goto label_1c198c;
            case 0x1C1998u: goto label_1c1998;
            case 0x1C19A4u: goto label_1c19a4;
            case 0x1C19B0u: goto label_1c19b0;
            case 0x1C19BCu: goto label_1c19bc;
            case 0x1C1A20u: goto label_1c1a20;
            case 0x1C1A70u: goto label_1c1a70;
            case 0x1C1A74u: goto label_1c1a74;
            case 0x1C1A7Cu: goto label_1c1a7c;
            case 0x1C1AD8u: goto label_1c1ad8;
            case 0x1C1B08u: goto label_1c1b08;
            case 0x1C1B14u: goto label_1c1b14;
            case 0x1C1B24u: goto label_1c1b24;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C1A84u;
    // 0x1c1a84: 0x0  nop
    ctx->pc = 0x1c1a84u;
    // NOP
    // 0x1c1a88: 0x80282d  daddu       $a1, $a0, $zero
    ctx->pc = 0x1c1a88u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c1a8c: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1c1a8cu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1c1a90: 0x90a30005  lbu         $v1, 0x5($a1)
    ctx->pc = 0x1c1a90u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 5), 5)));
    // 0x1c1a94: 0x3c020025  lui         $v0, 0x25
    ctx->pc = 0x1c1a94u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)37 << 16));
    // 0x1c1a98: 0x90a40007  lbu         $a0, 0x7($a1)
    ctx->pc = 0x1c1a98u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 5), 7)));
    // 0x1c1a9c: 0x2463ffff  addiu       $v1, $v1, -0x1
    ctx->pc = 0x1c1a9cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x1c1aa0: 0x24490688  addiu       $t1, $v0, 0x688
    ctx->pc = 0x1c1aa0u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 2), 1672));
    // 0x1c1aa4: 0x69260007  ldl         $a2, 0x7($t1)
    ctx->pc = 0x1c1aa4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 9), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 6, (GPR_U64(ctx, 6) & keepMask) | (mem << shift)); }
    // 0x1c1aa8: 0x6d260000  ldr         $a2, 0x0($t1)
    ctx->pc = 0x1c1aa8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 9), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 6, (GPR_U64(ctx, 6) & keepMask) | (mem >> shift)); }
    // 0x1c1aac: 0x8927000b  lwl         $a3, 0xB($t1)
    ctx->pc = 0x1c1aacu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 9), 11); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = (3u - offset) << 3; uint32_t keepMask = (shift == 0) ? 0u : ((1u << shift) - 1u); uint32_t merged = (GPR_U32(ctx, 7) & keepMask) | (mem << shift); SET_GPR_S32(ctx, 7, (int32_t)merged); }
    // 0x1c1ab0: 0x99270008  lwr         $a3, 0x8($t1)
    ctx->pc = 0x1c1ab0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 9), 8); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = offset << 3; uint32_t keepMask = (offset == 0) ? 0u : (0xFFFFFFFFu << ((4u - offset) << 3)); uint32_t merged32 = (GPR_U32(ctx, 7) & keepMask) | (mem >> shift); uint64_t merged64 = (GPR_U64(ctx, 7) & 0xFFFFFFFF00000000ull) | (uint64_t)merged32; if (offset == 0) merged64 = (uint64_t)(int64_t)(int32_t)merged32; SET_GPR_U64(ctx, 7, merged64); }
    // 0x1c1ab4: 0xb3a60007  sdl         $a2, 0x7($sp)
    ctx->pc = 0x1c1ab4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 6); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x1c1ab8: 0xb7a60000  sdr         $a2, 0x0($sp)
    ctx->pc = 0x1c1ab8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 6); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x1c1abc: 0xaba7000b  swl         $a3, 0xB($sp)
    ctx->pc = 0x1c1abcu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 11); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = (3u - offset) << 3; uint32_t mask = 0xFFFFFFFFu >> shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 7); uint32_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x1c1ac0: 0xbba70008  swr         $a3, 0x8($sp)
    ctx->pc = 0x1c1ac0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 8); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = offset << 3; uint32_t mask = 0xFFFFFFFFu << shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 7); uint32_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x1c1ac4: 0x30840003  andi        $a0, $a0, 0x3
    ctx->pc = 0x1c1ac4u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)3);
    // 0x1c1ac8: 0x14800003  bnez        $a0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C1AC8u;
    {
        const bool branch_taken_0x1c1ac8 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x1C1ACCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1AC8u;
            // 0x1c1acc: 0xa0a30005  sb          $v1, 0x5($a1) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 5), 5), (uint8_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c1ac8) {
            ctx->pc = 0x1C1AD8u;
            goto label_1c1ad8;
        }
    }
    ctx->pc = 0x1C1AD0u;
    // 0x1c1ad0: 0x2402001d  addiu       $v0, $zero, 0x1D
    ctx->pc = 0x1c1ad0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 29));
    // 0x1c1ad4: 0xa3a20001  sb          $v0, 0x1($sp)
    ctx->pc = 0x1c1ad4u;
    WRITE8(ADD32(GPR_U32(ctx, 29), 1), (uint8_t)GPR_U32(ctx, 2));
label_1c1ad8:
    // 0x1c1ad8: 0x90a20005  lbu         $v0, 0x5($a1)
    ctx->pc = 0x1c1ad8u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 5), 5)));
    // 0x1c1adc: 0x14400011  bnez        $v0, . + 4 + (0x11 << 2)
    ctx->pc = 0x1C1ADCu;
    {
        const bool branch_taken_0x1c1adc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1c1adc) {
            ctx->pc = 0x1C1B24u;
            goto label_1c1b24;
        }
    }
    ctx->pc = 0x1C1AE4u;
    // 0x1c1ae4: 0x90a20006  lbu         $v0, 0x6($a1)
    ctx->pc = 0x1c1ae4u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 5), 6)));
    // 0x1c1ae8: 0x2442ffff  addiu       $v0, $v0, -0x1
    ctx->pc = 0x1c1ae8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x1c1aec: 0x304300ff  andi        $v1, $v0, 0xFF
    ctx->pc = 0x1c1aecu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1c1af0: 0x14600008  bnez        $v1, . + 4 + (0x8 << 2)
    ctx->pc = 0x1C1AF0u;
    {
        const bool branch_taken_0x1c1af0 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1C1AF4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1AF0u;
            // 0x1c1af4: 0xa0a20006  sb          $v0, 0x6($a1) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 5), 6), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c1af0) {
            ctx->pc = 0x1C1B14u;
            goto label_1c1b14;
        }
    }
    ctx->pc = 0x1C1AF8u;
    // 0x1c1af8: 0x90a20007  lbu         $v0, 0x7($a1)
    ctx->pc = 0x1c1af8u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 5), 7)));
    // 0x1c1afc: 0x14400002  bnez        $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x1C1AFCu;
    {
        const bool branch_taken_0x1c1afc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1C1B00u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1AFCu;
            // 0x1c1b00: 0x2442ffff  addiu       $v0, $v0, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c1afc) {
            ctx->pc = 0x1C1B08u;
            goto label_1c1b08;
        }
    }
    ctx->pc = 0x1C1B04u;
    // 0x1c1b04: 0x24020063  addiu       $v0, $zero, 0x63
    ctx->pc = 0x1c1b04u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 99));
label_1c1b08:
    // 0x1c1b08: 0xa0a20007  sb          $v0, 0x7($a1)
    ctx->pc = 0x1c1b08u;
    WRITE8(ADD32(GPR_U32(ctx, 5), 7), (uint8_t)GPR_U32(ctx, 2));
    // 0x1c1b0c: 0x2402000c  addiu       $v0, $zero, 0xC
    ctx->pc = 0x1c1b0cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 12));
    // 0x1c1b10: 0xa0a20006  sb          $v0, 0x6($a1)
    ctx->pc = 0x1c1b10u;
    WRITE8(ADD32(GPR_U32(ctx, 5), 6), (uint8_t)GPR_U32(ctx, 2));
label_1c1b14:
    // 0x1c1b14: 0x90a20006  lbu         $v0, 0x6($a1)
    ctx->pc = 0x1c1b14u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 5), 6)));
    // 0x1c1b18: 0x5d1021  addu        $v0, $v0, $sp
    ctx->pc = 0x1c1b18u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 29)));
    // 0x1c1b1c: 0x9043ffff  lbu         $v1, -0x1($v0)
    ctx->pc = 0x1c1b1cu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 4294967295)));
    // 0x1c1b20: 0xa0a30005  sb          $v1, 0x5($a1)
    ctx->pc = 0x1c1b20u;
    WRITE8(ADD32(GPR_U32(ctx, 5), 5), (uint8_t)GPR_U32(ctx, 3));
label_1c1b24:
    // 0x1c1b24: 0x3e00008  jr          $ra
    ctx->pc = 0x1C1B24u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C1B28u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1B24u;
            // 0x1c1b28: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C1918u: goto label_1c1918;
            case 0x1C1924u: goto label_1c1924;
            case 0x1C1930u: goto label_1c1930;
            case 0x1C193Cu: goto label_1c193c;
            case 0x1C1948u: goto label_1c1948;
            case 0x1C1954u: goto label_1c1954;
            case 0x1C1980u: goto label_1c1980;
            case 0x1C198Cu: goto label_1c198c;
            case 0x1C1998u: goto label_1c1998;
            case 0x1C19A4u: goto label_1c19a4;
            case 0x1C19B0u: goto label_1c19b0;
            case 0x1C19BCu: goto label_1c19bc;
            case 0x1C1A20u: goto label_1c1a20;
            case 0x1C1A70u: goto label_1c1a70;
            case 0x1C1A74u: goto label_1c1a74;
            case 0x1C1A7Cu: goto label_1c1a7c;
            case 0x1C1AD8u: goto label_1c1ad8;
            case 0x1C1B08u: goto label_1c1b08;
            case 0x1C1B14u: goto label_1c1b14;
            case 0x1C1B24u: goto label_1c1b24;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C1B2Cu;
    // 0x1c1b2c: 0x0  nop
    ctx->pc = 0x1c1b2cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
