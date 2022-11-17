if(TEST_PLAYGROUND_TESTING_IS_ENABLED)
	add_executable(TestPlayground_unity_tests)
	target_link_libraries(TestPlayground_unity_tests PRIVATE unity_dep test_problems)
	target_sources(TestPlayground_unity_tests PRIVATE
		main.c
		test_suite_template.c
	)

	register_unity_test(TestPlayground.Unity.Test TestPlayground_unity_tests)
endif(TEST_PLAYGROUND_TESTING_IS_ENABLED)
