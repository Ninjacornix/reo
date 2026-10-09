#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A1910
// Address: 0x1a1910 - 0x1a1970
void sub_001A1910_0x1a1910(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A1910_0x1a1910");
#endif

    ctx->pc = 0x1a1910u;

    // 0x1a1910: 0x84890000  lh          $t1, 0x0($a0)
    ctx->pc = 0x1a1910u;
    SET_GPR_S32(ctx, 9, (int16_t)READ16(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1a1914: 0x3c02002b  lui         $v0, 0x2B
    ctx->pc = 0x1a1914u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)43 << 16));
    // 0x1a1918: 0x84880002  lh          $t0, 0x2($a0)
    ctx->pc = 0x1a1918u;
    SET_GPR_S32(ctx, 8, (int16_t)READ16(ADD32(GPR_U32(ctx, 4), 2)));
    // 0x1a191c: 0x558c0  sll         $t3, $a1, 3
    ctx->pc = 0x1a191cu;
    SET_GPR_S32(ctx, 11, (int32_t)SLL32(GPR_U32(ctx, 5), 3));
    // 0x1a1920: 0x2442ff20  addiu       $v0, $v0, -0xE0
    ctx->pc = 0x1a1920u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967072));
    // 0x1a1924: 0x84870004  lh          $a3, 0x4($a0)
    ctx->pc = 0x1a1924u;
    SET_GPR_S32(ctx, 7, (int16_t)READ16(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x1a1928: 0x84860006  lh          $a2, 0x6($a0)
    ctx->pc = 0x1a1928u;
    SET_GPR_S32(ctx, 6, (int16_t)READ16(ADD32(GPR_U32(ctx, 4), 6)));
    // 0x1a192c: 0x4b5021  addu        $t2, $v0, $t3
    ctx->pc = 0x1a192cu;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 11)));
    // 0x1a1930: 0x3c02002b  lui         $v0, 0x2B
    ctx->pc = 0x1a1930u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)43 << 16));
    // 0x1a1934: 0x2442ff22  addiu       $v0, $v0, -0xDE
    ctx->pc = 0x1a1934u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967074));
    // 0x1a1938: 0x4b1821  addu        $v1, $v0, $t3
    ctx->pc = 0x1a1938u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 11)));
    // 0x1a193c: 0x3c02002b  lui         $v0, 0x2B
    ctx->pc = 0x1a193cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)43 << 16));
    // 0x1a1940: 0x2442ff24  addiu       $v0, $v0, -0xDC
    ctx->pc = 0x1a1940u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967076));
    // 0x1a1944: 0xa5490000  sh          $t1, 0x0($t2)
    ctx->pc = 0x1a1944u;
    WRITE16(ADD32(GPR_U32(ctx, 10), 0), (uint16_t)GPR_U32(ctx, 9));
    // 0x1a1948: 0x4b1021  addu        $v0, $v0, $t3
    ctx->pc = 0x1a1948u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 11)));
    // 0x1a194c: 0xa5480002  sh          $t0, 0x2($t2)
    ctx->pc = 0x1a194cu;
    WRITE16(ADD32(GPR_U32(ctx, 10), 2), (uint16_t)GPR_U32(ctx, 8));
    // 0x1a1950: 0xa0202d  daddu       $a0, $a1, $zero
    ctx->pc = 0x1a1950u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a1954: 0xa5470004  sh          $a3, 0x4($t2)
    ctx->pc = 0x1a1954u;
    WRITE16(ADD32(GPR_U32(ctx, 10), 4), (uint16_t)GPR_U32(ctx, 7));
    // 0x1a1958: 0xa5460006  sh          $a2, 0x6($t2)
    ctx->pc = 0x1a1958u;
    WRITE16(ADD32(GPR_U32(ctx, 10), 6), (uint16_t)GPR_U32(ctx, 6));
    // 0x1a195c: 0x84660000  lh          $a2, 0x0($v1)
    ctx->pc = 0x1a195cu;
    SET_GPR_S32(ctx, 6, (int16_t)READ16(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1a1960: 0x84470000  lh          $a3, 0x0($v0)
    ctx->pc = 0x1a1960u;
    SET_GPR_S32(ctx, 7, (int16_t)READ16(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1a1964: 0x80697b0  j           func_1A5EC0
    ctx->pc = 0x1A1964u;
    ctx->pc = 0x1A1968u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A1964u;
            // 0x1a1968: 0x85450000  lh          $a1, 0x0($t2) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int16_t)READ16(ADD32(GPR_U32(ctx, 10), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A5EC0u;
    if (runtime->hasFunction(0x1A5EC0u)) {
        auto targetFn = runtime->lookupFunction(0x1A5EC0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001A5EC0_0x1a5ec0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1A196Cu;
    // 0x1a196c: 0x0  nop
    ctx->pc = 0x1a196cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
